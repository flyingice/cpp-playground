#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
  int val = 0;
  vector<Node*> children;
  
  Node(){}
  Node(int _val, vector<Node*> _children){
    val = _val;
    children = _children;
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes an n-ary tree to a binary tree.
// left child, right brother
TreeNode* encode(Node* root) {
  if(root == NULL) return NULL;

  TreeNode* rootBinary = new TreeNode(root->val);
  
  int sz = root->children.size();
  rootBinary->left = sz > 0 ? encode(root->children[0]) : NULL;

  TreeNode* current = rootBinary->left;
  for(int i = 1; i < sz; ++i) {
    current->right = encode(root->children[i]);
    current = current->right;
  }

  return rootBinary;
}

// Decodes your binary tree to an n-ary tree.
Node* decode(TreeNode* root) {
  if(root == NULL) return NULL;

  Node* rootN = new Node(root->val, {});
  TreeNode* current = root->left;
  Node* tmp = decode(current);
  if(tmp) {
    rootN->children.push_back(tmp);
    while(current && (tmp = decode(current->right))) {
      rootN->children.push_back(tmp);
      current = current->right;
    }
  }

  return rootN;
}

int main() {
  return 0;
}
