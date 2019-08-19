#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// implement a max heap
void sink(vector<int>& v, int low, int high) {
  while (low < high) {
    int leftChild = (low + 1) * 2 - 1;
    int rightChild = (low + 1) * 2;
    int candidate = leftChild;
    if (rightChild <= high && v[rightChild] > v[candidate]) candidate = rightChild;
    if (candidate <= high && v[candidate] > v[low]) {
      swap(v[candidate], v[low]);
      low = candidate;
    }
    else {
      low = high;
    }
  }
}

void my_make_heap(vector<int>& v, int low, int high) {
  for (int i = high; i >= low; i--) {
    sink(v, i, high);
  }
}

void my_push_heap(vector<int>& v, int low, int high) {
  while (high > low) {
    int parent = (high + 1) / 2 - 1;
    if (parent >= low && v[high] > v[parent]) {
      swap(v[high], v[parent]);
      high = parent;
    }
    else {
      high = low;
    }
  }
}

void my_pop_heap(vector<int>& v, int low, int high) {
  if (low < high) {
    swap(v[low], v[high]);
    sink(v, low, high - 1);
  }
}

void sort_standard(vector<int>& v) {
  make_heap(v.begin(), v.end());

  for (size_t i = 0; i < v.size(); i++) {
    pop_heap(v.begin(), v.end() - i);
  }
}

void sort_my_heap(vector<int>& v) {
  my_make_heap(v, 0, v.size() - 1);

  for (size_t i = 0; i < v.size(); i++) {
    my_pop_heap(v, 0, v.size() - 1 - i);
  }
}

void print(const vector<int>& v) {
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main() {
  vector<int> v = { 3, 5, 6, 1, 0, 9, 4 };
  vector<int> vv(v);

  sort_standard(v);
  print(v);

  sort_my_heap(vv);
  print(vv);

  return 0;
}
