/*
 * Each grid in a matrix can have 3 values:
 * 0 - trench
 * 1 - flat
 * 9 - obstacle
 * Starting from the top-left, find the minimal distance to cover to
 * find the only obstacle. One can move up/down/left/right, without
 * touching any trench.
 */
#include <queue>
#include <vector>
using namespace std;

int miniDistance(vector<vector<int>>& v) {
  static const int TRENCH = 0;
  static const int OBSTACLE = 9;

  if (v.empty() || v[0].empty()) return 0;

  int rowNum = v.size(), colNum = v[0].size();
  int level = 0;
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
      int row = q.front().first, col = q.front().second;
      q.pop();
      // up
      if (row > 0 && v[row - 1][col] != TRENCH) {
        if (v[row - 1][col] == OBSTACLE) return level + 1;
        v[row - 1][col] = TRENCH;
        q.emplace(row - 1, col);
      }
      // down
      if (row < rowNum - 1 && v[row + 1][col] != TRENCH) {
        if (v[row + 1][col] == OBSTACLE) return level + 1;
        v[row + 1][col] = TRENCH;
        q.emplace(row + 1, col);
      }
      // left
      if (col > 0 && v[row][col - 1] != TRENCH) {
        if (v[row][col - 1] == OBSTACLE) return level + 1;
        v[row][col - 1] = TRENCH;
        q.emplace(row, col - 1);
      }
      // right
      if (col < colNum - 1 && v[row][col + 1] != TRENCH) {
        if (v[row][col + 1] == OBSTACLE) return level + 1;
        v[row][col + 1] = TRENCH;
        q.emplace(row, col + 1);
      }
    }

    level++;
  }

  return 0;
}

int main() {
  return 0;
}