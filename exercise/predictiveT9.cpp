#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
  Node() : isWord(false){};
  virtual ~Node() = default;

  unordered_map<char, Node*> children;
  bool isWord;
};

class PrefixTree {
 public:
  PrefixTree() : root(new Node()) {
  }
  virtual ~PrefixTree() {
    // post-order traversal
    stack<pair<Node*, unordered_map<char, Node*>::iterator>> s;
    if (root) s.emplace(root, root->children.begin());
    while (!s.empty()) {
      Node* current = s.top().first;
      auto& it = s.top().second;
      if (it == current->children.end()) {
        // visit the node
        s.pop();
        delete current;
      }
      else {
        s.emplace(it->second, it->second->children.begin());
        it++;
      }
    }
  }

  bool insert(const string& word) {
    bool hasInserted = false;
    Node* current = root;
    for (size_t i = 0; i < word.size(); i++) {
      if (current->children.count(word[i]) == 0) {
        current->children[word[i]] = new Node();
        hasInserted = true;
      }
      current = current->children[word[i]];
    }
    if (current != root) current->isWord = true;

    return hasInserted;
  }

  bool hasWord(const string& word) {
    Node* current = root;
    for (size_t i = 0; i < word.size(); i++) {
      if (current->children.count(word[i]) == 0) return false;
      current = current->children[word[i]];
    }

    return current->isWord;
  }

  Node* getRoot() const {
    return root;
  }

 private:
  Node* root;
};

void findAllCombinationsHelper(const string& digits, int idx, Node* root, string& tmp, vector<string>& res) {
  const static vector<string> m = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

  if (idx >= digits.size() && !tmp.empty())
    res.push_back(tmp);
  else {
    size_t offset = digits[idx] - '2';  // assume that the input digit string is always valid
    for (size_t i = 0; i < m[offset].size(); i++) {
      if (root && root->children.count(m[offset][i])) {  // prune using the prefix tree
        tmp.push_back(m[offset][i]);
        findAllCombinationsHelper(digits, idx + 1, root->children[m[offset][i]], tmp, res);
        tmp.pop_back();
      }
    }
  }
}

vector<string> findAllCombinations(const string& digits, Node* dict) {
  vector<string> res;
  string tmp;
  findAllCombinationsHelper(digits, 0, dict, tmp, res);
  return res;
}

int main() {
  PrefixTree tree;
  tree.insert("apple");
  tree.insert("pineapple");
  tree.insert("pear");
  tree.insert("super");

  cout << boolalpha << tree.hasWord("apple") << endl;
  cout << boolalpha << tree.hasWord("pineapple") << endl;
  cout << boolalpha << tree.hasWord("pear") << endl;
  cout << boolalpha << tree.hasWord("pea") << endl;
  cout << boolalpha << tree.hasWord("banana") << endl;
  cout << boolalpha << tree.hasWord("") << endl;

  // super: 78737
  vector<string> v = findAllCombinations("78737", tree.getRoot());
  copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));

  return 0;
}