// Given rows * cols matrix.
// Select cols-1 elements from each row such that that the resulting sum is minimum
// and each column is selected at least once.
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int findMinSum(const vector<vector<int>>& matrix) {
  if (matrix.empty() || matrix[0].empty()) return 0;

  int row = matrix.size(), col = matrix[0].size();
  vector<pair<int, int>> position;  // record the index of the largest and 2nd largest element of each row
  int sum = 0;
  for (int i = 0; i < row; i++) {
    int first = 0, second = 0;
    for (int j = 0; j < col; j++) {
      sum += matrix[i][j];
      if (matrix[i][j] >= matrix[i][first]) {
        second = first;
        first = j;
      }
      else if (matrix[i][j] > matrix[i][second]) {
        second = j;
      }
    }
    position.emplace_back(first, second);
    sum -= matrix[i][first];
  }

  int i = 1;
  while (i < row && position[i].first == position[i - 1].first) i++;
  if (i == row) {  // all the max elements are on the same column
    int diff = numeric_limits<int>::max();
    for (int j = 0; j < row; j++) {
      diff = min(diff, matrix[j][position[j].first] - matrix[j][position[j].second]);
    }
    sum += diff;
  }

  return sum;
}

int main() {
  vector<vector<int>> v = {
    { 2, 3, 5 },
    { 3, 2, 5 },
    { 4, 4, 7 },
  };

  cout << findMinSum(v) << endl;

  return 0;
}