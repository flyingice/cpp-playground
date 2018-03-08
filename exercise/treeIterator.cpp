#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class Node {
public:
  Node(): left(NULL), right(NULL) {}
  Node(char iData, Node* iLeft = NULL, Node* iRight = NULL): data(iData), left(iLeft), right(iRight) {} 
  virtual ~Node() {}

  char getData() const { return data; }

  char data;
  Node* left;
  Node* right;
};

class BinaryTree {
public:
  BinaryTree(): root(NULL) {}
  BinaryTree(char iData): root(new Node(iData)) {}
  virtual ~BinaryTree() { delTree(root); }

  bool isEmpty() const { return root == NULL; }
  Node* getRoot() const { return root; }
  void delTree(Node* iRoot);

  Node* root;
};

void BinaryTree::delTree(Node* iRoot) {
  if (iRoot) {
    delTree(iRoot->left);
    delTree(iRoot->right);
    delete iRoot;
  }
}

class BinaryTreeItr {
public:
  BinaryTreeItr(const BinaryTree& iTree): tree(iTree), current(NULL) {}
  virtual ~BinaryTreeItr() {}

  virtual void first() = 0;
  virtual void operator++() = 0;
  bool operator+() const { return current; }
  const char operator()() const { return current->getData(); }

  const BinaryTree& tree;
  const Node* current;
};

class PreOrderItr: public BinaryTreeItr {
public:
  PreOrderItr(const BinaryTree& tree): BinaryTreeItr(tree) {}
  virtual ~PreOrderItr() { stack<Node*>().swap(s); }

  virtual void first();
  virtual void operator++();
  virtual void print();

private:
  stack<Node*> s;
};

void PreOrderItr::first() {
  // clear remaning elements in the stack
  stack<Node*>().swap(s);
  // push root into the stack
  if (tree.getRoot()) {
    s.push(tree.getRoot());
    operator++();
  }
}

void PreOrderItr::operator++() {
  if (s.empty()) {
    current = NULL;
    return;
  }

  current = s.top();
  s.pop();
  if (current->right) s.push(current->right);
  if (current->left) s.push(current->left);
}

void PreOrderItr::print() {
  cout << "PreOrder:" << endl;
  first();
  while(operator+()) {
    cout << operator()() << " ";
    operator++();
  }
  cout << endl;
}

class PostOrderItr: public BinaryTreeItr {
public:
  PostOrderItr(const BinaryTree& tree): BinaryTreeItr(tree) {}
  virtual ~PostOrderItr() { stack<pair<Node*, int> >().swap(s); }

  virtual void first();
  virtual void operator++();
  virtual void print();

  stack<pair<Node*, int> > s;
};

void PostOrderItr::first() {
  stack<pair<Node*, int> >().swap(s);

  if(tree.getRoot()) {
    pair<Node*, int> pr(tree.getRoot(), 0);
    s.push(pr);
    operator++();
  }
}

void PostOrderItr::operator++() {
  while (!s.empty() && s.top().second < 1) {  // the node is being accessed the 1st time
    Node* p = s.top().first;
    ++s.top().second;

    if (p->right) {
      s.push(make_pair<Node*, int>(p->right, 0));
    }

    if (p->left) {
      s.push(make_pair<Node*, int>(p->left, 0));
    }
  }

  if (s.empty()) {
    current = NULL;
    return;
  } else {
    current = s.top().first;
    s.pop();
  }
}

void PostOrderItr::print() {
  cout << "PostOrder:" << endl;
  first();
  while(operator+()) {
    cout << operator()() << " ";
    operator++();
  }
  cout << endl;
}

class InOrderItr: public BinaryTreeItr {
public:
  InOrderItr(const BinaryTree& tree): BinaryTreeItr(tree) {}
  virtual ~InOrderItr() { stack<pair<Node*, int> >().swap(s); }

  virtual void first();
  virtual void operator++();
  virtual void print();

  stack<pair<Node*, int> > s;
};

void InOrderItr::first() {
  stack<pair<Node*, int> >().swap(s);

  if (tree.getRoot()) {
    s.push(make_pair<Node*, int>(tree.getRoot(), 0));
    operator++();
  }
}

void InOrderItr::operator++() {
  while (!s.empty() && s.top().second < 1) {
    ++s.top().second;
    Node* p = s.top().first;

    if (p->left) {
      s.push(make_pair<Node*, int>(p->left, 0));
    }
  }

  if (s.empty()) {
    current = NULL;
    return;
  } else {
    current = s.top().first;
    s.pop();
    if (current->right) {
      s.push(make_pair<Node*, int>(current->right, 0));
    }
  }
}

void InOrderItr::print() {
  cout << "InOrder:" << endl;
  first();
  while(operator+()) {
    cout << operator()() << " ";
    operator++();
  }
  cout << endl;
}

void init(BinaryTree& t) {
  t.root = new Node('A');
  t.root->left = new Node('L');
  t.root->right = new Node('C');

  t.root->left->left = new Node('B');
  t.root->left->right = new Node('E');
  t.root->right->right = new Node('D');

  t.root->right->right->left = new Node('W');

  t.root->right->right->left->right = new Node('X');
}

int main() {
  BinaryTree t;
  init(t);

  PreOrderItr preOrderItr(t);
  preOrderItr.print();

  PostOrderItr postOrderItr(t);
  postOrderItr.print();

  InOrderItr inOrderItr(t);
  inOrderItr.print();

  return 0;
}
