#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// definition for directed graph
struct DirectedGraphNode {
  int label;
  vector<DirectedGraphNode*> neighbors;
  DirectedGraphNode(int x) : label(x){};
};

vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
  // calculate indegree of each node
  unordered_map<DirectedGraphNode*, int> m;
  for (DirectedGraphNode* node : graph) {
    for (DirectedGraphNode* neighbor : node->neighbors) {
      ++m[neighbor];
    }
  }

  vector<DirectedGraphNode*> order;

  // enqueue all the nodes with zero indegree
  queue<DirectedGraphNode*> q;
  for (DirectedGraphNode* node : graph) {
    if (m[node] == 0) {
      order.push_back(node);
      q.push(node);
    }
  }

  // breadth-first search
  while (!q.empty()) {
    DirectedGraphNode* p = q.front();
    q.pop();

    for (DirectedGraphNode* neighbor : p->neighbors) {
      if (--m[neighbor] == 0) {
        order.push_back(neighbor);
        q.push(neighbor);
      }
    }
  }

  return order;
}

int main() {
  return 0;
}
