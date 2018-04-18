#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Node {
public:
  int val = 0;
  vector<Node*> children;

  Node() {}

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// Encodes a tree to a single string.
string serialize(Node* root) {
  ostringstream os;
  if(root) {
    os << " " << root->val << " " << root->children.size();
    for(int i = 0; i < root->children.size(); ++i) {
      os << serialize(root->children[i]);
    }
  }

  return os.str();
}

Node* deserializeHelper(istringstream& is) {
  Node* root = NULL;

  int val, cnt;
  if(is >> val >> cnt) {
    root = new Node(val, {});
    for(int i = 0; i < cnt; ++i) {
      root->children.push_back(deserializeHelper(is));
    }
  }

  return root;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
  istringstream is(data);
  return deserializeHelper(is);
}

int main() {
  return 0;
}
