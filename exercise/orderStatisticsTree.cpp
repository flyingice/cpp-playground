#include <iostream>
#include <cassert>
using namespace std;

class Node {
  public:
    Node(): size(1), left(NULL), right(NULL) {}
    Node(int iData, Node* iLeft = NULL, Node* iRight = NULL): data(iData), size(1), left(iLeft), right(iRight) {}
    virtual ~Node() {}
    
    int data, size;
    Node* left;
    Node* right;
};

class OrderStatisticsTree {
  public:
    OrderStatisticsTree():root(NULL) {}
    virtual ~OrderStatisticsTree() { delTree(root); }

    void delTree(Node* iRoot);

    void printPreOrder(const Node* iRoot) const;

    Node* findKth(int k, Node* iRoot) const;
    bool insert(int iData, Node*& iRoot);
    bool remove(int iData, Node*& iRoot); 

    Node* root;
};

void OrderStatisticsTree::delTree(Node* iRoot) {
  if(iRoot) {
    delTree(iRoot->left);
    delTree(iRoot->right);
    delete iRoot;
  }
}

void OrderStatisticsTree::printPreOrder(const Node* iRoot) const {
  if(iRoot) {
    cout << "data|size " << iRoot->data << "|" << iRoot->size << endl;
    printPreOrder(iRoot->left);
    printPreOrder(iRoot->right);
  }
}

Node* OrderStatisticsTree::findKth(int k, Node* iRoot) const {
  if(iRoot == NULL) return NULL;

  int n = 0;
  if(iRoot->left) n = iRoot->left->size;
  if(k == n + 1) {
    return iRoot;
  } else if(k < n + 1) {
    return findKth(k, iRoot->left);
  } else {
    return findKth(k - n - 1, iRoot->right);
  }
}

bool OrderStatisticsTree::insert(int iData, Node*& iRoot) {
  if(iRoot == NULL) {
    return (iRoot = new Node(iData)) != NULL;
  }
    
  if(iData < iRoot->data) {
    return insert(iData, iRoot->left) ? ++iRoot->size : 0;
  } else if(iData > iRoot->data) {
    return insert(iData, iRoot->right) ? ++iRoot->size: 0;
  } else {  // the node with the same data already exists
    return false;
  }
}

bool OrderStatisticsTree::remove(int iData, Node*& iRoot) {
  if(iRoot == NULL) return false;

  if(iData < iRoot->data) {
    return remove(iData, iRoot->left) ? iRoot->size-- : 0;
  } else if(iData > iRoot->data) {
    return remove(iData, iRoot->right) ? iRoot->size-- : 0;
  } else {  // the right node has been found
    if (iRoot->left && iRoot->right) {
      Node* p = iRoot->left;
      while(p->right) p = p->right;
      int d = p->data;
      remove(d, iRoot);
      iRoot->data = d;
    } else {
      Node* p = iRoot;
      iRoot = (iRoot->left ? iRoot->left : iRoot->right);
      delete p;
    }

    return true;
  }
}

void init(OrderStatisticsTree& tree) {
  tree.insert(50, tree.root);
  tree.insert(20, tree.root);
  tree.insert(60, tree.root);
  tree.insert(15, tree.root);
  tree.insert(30, tree.root);
  tree.insert(70, tree.root);
}

int main() {
  OrderStatisticsTree tree;
  init(tree);

  tree.printPreOrder(tree.root);

  assert(tree.root);
  Node* p = NULL;
  for(int i = 0; i < tree.root->size; ++i) {
    p = tree.findKth(i + 1, tree.root);
    if(p) {
      cout << i + 1 << ": " << p->data << endl;
    }
  }

  /* NULL test */
  p = tree.findKth(tree.root->size + 1, tree.root);
  if (p == NULL) {
    cout << "The node doesn't exist" << endl;
  }
  p = tree.findKth(0, tree.root);
  if (p == NULL) {
    cout << "The node doesn't exist" << endl;
  }

  cout << "remove 20..." << endl;
  tree.remove(20, tree.root);
  tree.printPreOrder(tree.root);

  cout << "remove 60..." << endl;
  tree.remove(60, tree.root);
  tree.printPreOrder(tree.root);

  cout << "remove 70..." << endl;
  tree.remove(70, tree.root);
  tree.printPreOrder(tree.root);

  for(int i = 0; i < tree.root->size; ++i) {
    p = tree.findKth(i + 1, tree.root);
    if(p) {
      cout << i + 1 << ": " << p->data << endl;
    }
  }

  return 0;
}
