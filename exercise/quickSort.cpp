#include <chrono>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>
#include <utility>
#include <string>
using namespace std;

typedef void(*fp)(vector<int>&, int, int);

void quickSortRecursiveA(vector<int>& v, int left, int right) {
  if(left >= right) return;

  // partition
  int pivot = v[left];
  // slower pointer keeping track of the tail (past + 1) of the elements smaller than the chosen pivot
  int j = left + 1;
  for(int i = left + 1; i <= right; ++i) {
    if(v[i] < pivot) swap(v[i], v[j++]);
  }
  // at the end of the loop, v[j - 1] is the element to swap with the pivot
  swap(v[left], v[j - 1]);

  // recursion, v[j - 1] is already on the right position
  quickSortRecursiveA(v, left, j - 2);
  quickSortRecursiveA(v, j, right);
}

// The most elegant version
void quickSortRecursiveB(vector<int>& v, int left, int right) {
  if(left >= right) return;

  int pivot = v[left];
  int j = left;
  for(int i = left + 1; i <= right; ++i) {
    if(v[i] < pivot) swap(v[i], v[++j]);
  }

  swap(v[left], v[j]);

  quickSortRecursiveB(v, left, j - 1);
  quickSortRecursiveB(v, j + 1, right);
}

void quickSortIterative(vector<int>& v, int left, int right) {
  typedef pair<int, int> SortRange;
  stack<SortRange> s;
  s.push(make_pair(left, right));

  while(!s.empty()) {
    SortRange r = s.top();
    s.pop();
    // partition
    int pivot = v[r.first];
    int j = r.first;
    for(int i = r.first + 1; i <= r.second; ++i) {
      if(v[i] < pivot) swap(v[i], v[++j]);
    }
    swap(v[r.first], v[j]);

    // since pivot is already in the right position
    if(j - 1 > r.first) s.push(make_pair(r.first, j - 1));
    if(j + 1 < r.second) s.push(make_pair(j + 1, r.second));
  }
}

void randomGenerator(vector<int>& v, int maxSize, int maxNum) {
  vector<int>().swap(v);

  int size = 1 + rand() % maxSize;
  for(int i = 0; i < size; ++i) v.push_back(rand() % (maxNum + 1)); 
}

void print(const vector<int>& v) {
  ostream_iterator<int> out(cout, " ");
  copy(v.begin(), v.end(), out);
  cout << endl;
}

bool checkSortResult(const vector<int>& v) {
  vector<int> ref(v);
  sort(ref.begin(), ref.end()); // STL version

  return ref == v;
}

void runAndCheck(fp f, vector<int>& v, const string& fName) {  
  randomGenerator(v, 20, 50);
  cout << "before sort: " << fName << endl;
  print(v);

  f(v, 0, v.size() - 1);
  cout << "after sort: " << (checkSortResult(v) ? "OK" : "KO") << endl;
  print(v);
}

int main() {
  vector<int> v;
  srand(time(NULL));

  runAndCheck(&quickSortRecursiveA, v, "quickSortRecursiveA");
  runAndCheck(&quickSortRecursiveB, v, "quickSortRecursiveB");
  runAndCheck(&quickSortIterative, v, "quickSortIterative");

  /* Performance check to sort 1GB 4-byte integers: above 20s
   * In thoery according to Jeff Dean of Google,
   * sort time = comparaison time (branch miss) + memory access
   *  = 2^28 * log(2 ^ 28) * 5ns + 28 * 1GB / 4GB/s = 21s + 7s = 28s
   */
  randomGenerator(v, 1 << 28, RAND_MAX);
  auto begin = chrono::system_clock::now();
  sort(v.begin(), v.end());
  auto end = chrono::system_clock::now();
  cout << "elapse time to sort 1GB integers: " << chrono::duration_cast<chrono::seconds>(end - begin).count() << "s"
       << endl;
}
