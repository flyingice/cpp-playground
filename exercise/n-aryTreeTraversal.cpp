#include <stack>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Node {
  public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
    }
};

vector<int> preorder(Node* root) {
  vector<int> res;
  stack<Node*> s;
  if(root) s.push(root);
  while(!s.empty()) {
    Node* p = s.top();
    s.pop();
    res.push_back(p->val);

    for(auto it = p->children.rbegin(); it != p->children.rend(); ++it) {
      if(*it) s.push(*it);
    }
  }

  return res;
}

vector<int> postorder(Node* root) {
  vector<int> res;
  stack<pair<Node*, int>> s;

  if(root) s.push(make_pair(root, 0));
  while(!s.empty()) {
    pair<Node*, int> p = s.top();
    int next = p.second;
    while(next < p.first->children.size() && p.first->children[next] == NULL) ++next;

    if(next == p.first->children.size()) {
      s.pop();
      res.push_back(p.first->val);
    } else {
      s.top().second = next + 1;
      s.push(make_pair(p.first->children[next], 0));
    }
  }

  return res;
}

vector<vector<int>> levelOrder(Node* root) {
  vector<vector<int>> res;
  queue<Node*> q;

  if(root) q.push(root);
  while(!q.empty()) {
    int sz = q.size();
    vector<int> level;
    for(int i = 0; i < sz; ++i) {
      Node* p = q.front();
      q.pop();
      level.push_back(p->val);

      // enqueue its child
      for(Node* child: p->children) {
        if(child) q.push(child);
      }
    }
    res.push_back(level);
  }

  return res;
}

int main() {
  return 0;
}
