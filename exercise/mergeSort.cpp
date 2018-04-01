#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

typedef void(*fp)(vector<int>&, int, int);

void mergeSort(vector<int>& v, int left, int right) {
  if(left < right) {
    int mid = left + ((right - left) >> 1);
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);

    // merge two sorted lists
    int* tmp = new int[right - left + 1];
    int i = left, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right) {
      if(v[i] < v[j]) tmp[k++] = v[i++];
      else tmp[k++] = v[j++];
    }

    if(i <= mid) {
      for(int t = 0; t <= mid - i; ++t) v[right - t] = v[mid - t];
    }
    // otherwise when j <= right the remaining elements are already in the right position
    // copy the data from the temporary array back to the inital array
    for(int t = 0; t < k; ++t) v[left + t] = tmp[t];

    delete [] tmp;
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
 
  runAndCheck(&mergeSort, v, "mergeSort");
}
