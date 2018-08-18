#include <algorithm>
using namespace std;

typedef struct node {
  int val;
  struct node* left;
  struct node* right;
  int ht;
} Node;

int height(const node* root) {
  return root ? root->ht : -1;
}

// rotate from left to right
void rightRotate(node*& root) {
  node* k1   = root->left;
  root->left = k1->right;
  root->ht   = max(height(root->left), height(root->right)) + 1;
  k1->right  = root;
  root       = k1;
  root->ht   = max(height(root->left), height(root->right)) + 1;
}

// rotate from right to left
void leftRotate(node*& root) {
  node* k1    = root->right;
  root->right = k1->left;
  root->ht    = max(height(root->left), height(root->right)) + 1;
  k1->left    = root;
  root        = k1;
  root->ht    = max(height(root->left), height(root->right)) + 1;
}

void leftRightDoubleRotate(node*& root) {
  leftRotate(root->left);
  rightRotate(root);
}

void rightLeftDoubleRotate(node*& root) {
  rightRotate(root->right);
  leftRotate(root);
}

void balance(node*& root) {
  if (root == nullptr) return;

  int lHeight = height(root->left), rHeight = height(root->right);
  // adjust height
  root->ht = max(lHeight, rHeight) + 1;
  // rebalance
  if (lHeight - rHeight > 1) {
    if (height(root->left->right) > height(root->left->left))
      leftRightDoubleRotate(root);
    else
      rightRotate(root);
  }
  else if (rHeight - lHeight > 1) {
    if (height(root->right->left) > height(root->right->right))
      rightLeftDoubleRotate(root);
    else
      leftRotate(root);
  }
}

void insertNode(node*& root, int val) {
  if (root == nullptr)
    root = new node{ val, nullptr, nullptr, 0 };
  else if (root->val > val)
    insertNode(root->left, val);
  else if (root->val < val)
    insertNode(root->right, val);

  balance(root);
}

node* insert(node* root, int val) {
  insertNode(root, val);
  return root;
}

int main() {
  return 0;
}
