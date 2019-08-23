#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int binary_search(const vector<int>& v, int left, int right, int target, int offset) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    for (int i = mid - offset; i <= mid + offset; i++) {
      if (i >= left && i <= right && v[i] == target) return i;
    }

    if (target < v[mid])
      right = mid - offset - 1;
    else
      left = mid + offset + 1;
  }

  return -1;
}

int search(const vector<int>& v, int left, int right, int target) {
  while (left <= right) {
    if (v[left] == target) return left;
    left++;
  }

  return -1;
}

vector<int> randomizeAlmostSortedArray(int maxLength, int upperlimit, int posLimit, int maxOffset) {
  int sz = rand() % maxLength + 1;
  vector<int> v(sz);
  for (int i = 0; i < sz; i++) {
    v[i] = rand() % upperlimit;
  }

  sort(v.begin(), v.end());

  int sign = 1;
  int n = rand() % posLimit;

  int pos = rand() % posLimit;
  while (pos < sz && --n) {
    int target = pos + sign * (rand() % maxOffset + 1);
    if (target >= 0 && target < sz) swap(v[pos], v[target]);
    sign = (sign > 0 ? -1 : 1);
    pos += (2 * maxOffset + 1 + rand() % 10);
  }

  return v;
}

int main() {
  const static int OFFSET = 1;

  srand(time(NULL));

  for (int i = 0; i < 100; i++) {
    vector<int> v = randomizeAlmostSortedArray(100, 100, 10, OFFSET);
    int left = 0, right = v.size() - 1;

    int target = v[rand() % v.size()];
    int res1 = search(v, left, right, target);
    int res2 = binary_search(v, left, right, target, OFFSET);
    if (res2 == res1 || (res2 >= 0 && v[res2] == target))
      cout << "OK" << endl;
    else {
      cout << "KO: " << target << endl;
      copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
      cout << endl << "expected: " << res1 << " found: " << res2 << endl;
    }
  }

  return 0;
}