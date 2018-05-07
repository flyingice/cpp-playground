#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

void print(const vector<int>& v) {
  for(size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
  cout << endl;
}

int findLinear(const vector<int>&v , int left, int right) {
  int i = left;
  while(i <= right) {
    if(i + 1 <= right && v[i + 1] < v[i]) break;
    ++i;
  }

  return i > right ? v[right] : v[i];
}

int findBinary(const vector<int>& v, int left, int right) {
  while(left < right) {
    int mid = left + (right - left + 1) / 2;
    if((mid - 1 < left || v[mid - 1] < v[mid]) && (mid + 1 > right || v[mid] > v[mid + 1])) return v[mid];
    else if(mid - 1 < left || v[mid - 1] < v[mid]) left = mid;
    else right = mid - 1;
  }

  return v[left];
}

void generator(vector<int>& v, int size) {
  v.clear();
  v.resize(size);

  int start = 10;
  int turn = rand() % size;
  for(int i = 0; i <= turn; ++i) v[i] = start++;
  --start;
  for(int i = turn + 1; i < size; ++i) v[i] = --start;
}

int main() {
  srand(time(NULL));

  vector<int> v;
  for(int i = 0; i < 100; ++i) {
    int sz = 10;
    generator(v, sz);
    print(v);
    if(findBinary(v, 0, sz - 1) == findBinary(v, 0, sz - 1)) cout << "OK" << endl;
    else cout << "KO!!!" << endl; 
  }

  return 0;
}
