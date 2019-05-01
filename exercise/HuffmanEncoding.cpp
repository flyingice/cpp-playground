#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

struct TreeNode {
  TreeNode() : data(0), left(nullptr), right(nullptr) {
  }
  explicit TreeNode(char iData, TreeNode* iLeft = nullptr, TreeNode* iRight = nullptr)
      : data(iData), left(iLeft), right(iRight) {
  }
  virtual ~TreeNode() = default;

  char data;
  TreeNode* left;
  TreeNode* right;
};

typedef pair<TreeNode*, int> Entry;

struct Comparator {
  bool operator()(const Entry& left, const Entry& right) const {
    assert(left.first);
    assert(right.first);
    return (left.second > right.second) || (left.second == right.second && left.first->data > right.first->data);
  }
};

TreeNode* getHuffmanTree(const string& iStr) {
  priority_queue<Entry, vector<Entry>, Comparator> q;

  // collect frequence stats of each character
  unordered_map<char, int> stats;
  for (char c : iStr) stats[c]++;

  for (const auto& entry : stats) q.emplace(new TreeNode(entry.first), entry.second);

  while (q.size() > 1) {
    int weight = 0;
    weight += q.top().second;
    TreeNode* leftChild = q.top().first;
    q.pop();

    weight += q.top().second;
    TreeNode* rightChild = q.top().first;
    q.pop();

    q.emplace(new TreeNode('0', leftChild, rightChild), weight);
  }

  return q.size() > 0 ? q.top().first : nullptr;
}

void postOrderTraversal(TreeNode* iRoot) {
  string path;
  // The 1st int tracks how many times the node has been seen
  // while the 2nd int indicated whether it is the left or right
  // child of its parent
  stack<tuple<TreeNode*, int, char>> s;
  if (iRoot) s.push(make_tuple(iRoot, 0, '2'));  // 2 indicates no parent
  while (!s.empty()) {
    TreeNode* p = get<0>(s.top());
    int timeVisited = get<1>(s.top());
    char c = get<2>(s.top());
    if (timeVisited == 0) {
      get<1>(s.top())++;
      if (p->left) s.emplace(p->left, 0, '0');
      if (c != '2') path.push_back(c);
    }
    else if (timeVisited == 1) {
      get<1>(s.top())++;
      if (p->right) s.emplace(p->right, 0, '1');
    }
    else {  // visit the node
      if (p->left == nullptr && p->right == nullptr) cout << p->data << ": " << path << endl;
      if (!path.empty()) path.pop_back();
      s.pop();
    }
  }
}

void displayHuffmanEncoding(TreeNode* iRoot) {
  postOrderTraversal(iRoot);
}

int main() {
  TreeNode* root = getHuffmanTree("abbcccddd");
  displayHuffmanEncoding(root);

  return 0;
}