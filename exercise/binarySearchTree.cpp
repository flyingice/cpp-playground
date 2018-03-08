#include <iostream>
using namespace std;

class Node {
  public:
    Node(): left(NULL), right(NULL) {}
    Node(const int iData, Node* iLeft = NULL, Node* iRight = NULL): data(iData), left(iLeft), right(iRight) {} 
    virtual ~Node() {}

    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
  public:
    BinarySearchTree(): root(NULL) {}
    virtual ~BinarySearchTree() { delTree(root); }

    void delTree(Node* iRoot);
    void printInOrder(const Node* iRoot);
    
    Node* find(int iVal) const;
    void insert(int iVal, Node*& iRoot);  // recursive approach
    void insert(int iVal);  // iterative approach
    void remove(int iVal, Node*& iRoot); // recursive approach

    Node* root;
};

void BinarySearchTree::delTree(Node* iRoot) {
  if(iRoot) {
    delTree(iRoot->left);
    delTree(iRoot->right);
    delete iRoot;
  }
}

void BinarySearchTree::printInOrder(const Node* iRoot) {
  if(iRoot) {
    printInOrder(iRoot->left);
    cout << iRoot->data << " ";
    printInOrder(iRoot->right);
  }
}

Node* BinarySearchTree::find(int iVal) const {
  Node* p = root;
  while(p) {
    if(iVal == p->data) {
      return p;
    } else if(iVal < p->data) {
      p = p->left;
    } else {
      p = p->right;
    }
  }

  return NULL;
}

void BinarySearchTree::insert(int iVal, Node*& iRoot) {
  if(iRoot == NULL) {
    iRoot = new Node(iVal);
  }

  if(iVal < iRoot->data) {
    insert(iVal, iRoot->left);
  } else if(iVal > iRoot->data) {
    insert(iVal, iRoot->right);
  }
}

void BinarySearchTree::insert(int iVal) {
  if (root == NULL) {
    root = new Node(iVal);
    return;
  }

  Node* p = root;
  Node* parent = NULL;
  while(p) {
    parent = p;
    if(p->data == iVal) {
      return;
    } else if(iVal < p->data) {
      p = p->left;
    } else {
      p = p->right;
    }
  }

  if(iVal < parent->data) {
    parent->left = new Node(iVal);
  } else {
    parent->right = new Node(iVal);
  }
}

void BinarySearchTree::remove(int iVal, Node*& iRoot) {
  if(iRoot == NULL) return;

  if(iVal < iRoot->data) {
    remove(iVal, iRoot->left);
  } else if(iVal > iRoot->data) {
    remove(iVal, iRoot->right);
  } else {
    if (iRoot->left && iRoot->right) {
      // find the largest element of the left sub-tree
      Node* p = iRoot->left;
      while(p && p->right) p = p->right;
      int d = p->data;
      remove(d, iRoot);
      iRoot->data = d;
    } else {
      Node* p = iRoot;
      iRoot = iRoot->left ? iRoot->left : iRoot->right;
      delete p;
    }
  }
}

void init(BinarySearchTree& tree) {
  tree.root = new Node(50);

  tree.root->left = new Node(20);
  tree.root->right = new Node(60);

  tree.root->left->left = new Node(15);
  tree.root->left->right = new Node(30);
  tree.root->right->right = new Node(70);
}

int main() {
  BinarySearchTree tree;
  init(tree);

  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;
  
  cout << "find val 55: ";
  Node* p = tree.find(55);
  if (p) {
    cout << p->data;
  }
  cout << endl;

  cout << "insert 55..." << endl;
  tree.insert(55, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;
  
  cout << "find val 55: ";
  p = tree.find(55);
  if (p) {
    cout << p->data;
  }
  cout << endl;

  cout << "insert 100..." << endl;
  tree.insert(100);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;

  cout << "remove 100..." << endl;
  tree.remove(100, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;

  cout << "remove 55..." << endl;
  tree.remove(55, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;

  cout << "remove 20..." << endl;
  tree.remove(20, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;
  
  cout << "remove 15..." << endl;
  tree.remove(15, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;

  cout << "remove 50..." << endl;
  tree.remove(50, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;

  cout << "remove 200..." << endl;
  tree.remove(200, tree.root);
  cout << "printInOrder: ";
  tree.printInOrder(tree.root);
  cout << endl;

  return 0;
}
