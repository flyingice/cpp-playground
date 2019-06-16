#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  vector<int> v = { 3, 5, 6, 1, 0, 9, 4 };
  make_heap(v.begin(), v.end());

  for (size_t i = 0; i < v.size(); i++) {
    pop_heap(v.begin(), v.end() - i);
  }

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}