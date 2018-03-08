#include <iostream>
#include <vector>
#include <boost/assign/list_of.hpp>
using namespace std;

int LinearSearch(const vector<int>& v, int target) {
  for(int i = 0; i < v.size(); ++i) {
    if (v[i] == target) {
      return i;
    }
  }

  return -1;
}

// The elements of the input parameter v must be in order.
int BinarySearch_R(const vector<int>& v, int target, int left, int right) {
  if (left > right) {
    return -1;
  }

  int mid = left + ((right - left) >> 1);
  if (v[mid] == target) {
    return mid;
  } else if (v[mid] < target) { 
    return BinarySearch_R(v, target, mid + 1, right);
  } else {
    return BinarySearch_R(v, target, left, mid - 1);
  }
}

int BinarySearch_L(const vector<int>& v, int target) {
  int left = 0, right = v.size() - 1;
  while(left <= right) {
    int mid = left + ((right - left) >> 1); // avoid integer overflow
    if (v[mid] == target) {
      return mid;
    } else if (v[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

// Return the index with the min value, v is an increasing vector
int CyclicBinarySearch(const vector<int>& v) {
  int left = 0, right = v.size() - 1;
  while(left < right) {
    int mid = left + ((right - left) >> 1);
    if (v[mid] < v[right]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  if(left == right) {
    return left;
  } else {
    return -1;
  }
}

int main() {
  vector<int> v;
  v = boost::assign::list_of(0)(1)(2)(3)(4)(5)(6)(7)(8)(9);

  cout << "vector v contains " << v.size() << " elements" << endl;
  for(int i = 0; i < v.size(); ++i) {
    cout << "BinarySearch_R: " << BinarySearch_R(v, i, 0, v.size() -1) 
      << " BinarySearch_L: " << BinarySearch_L(v, i) << endl;
  }

  v = boost::assign::list_of(4)(5)(1)(2)(3);
  cout << "CyclicBinarySearch find index: " << CyclicBinarySearch(v) << endl;
  
  return 0;
}
