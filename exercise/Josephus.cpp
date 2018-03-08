#include <list>
#include <iostream>
#include <string>
using namespace std;

static const int PEOPLE = 6;
static const int STEP = 2;

int brute_force(int n, int k) {
  list<int> l;
  for (size_t i = 0; i < n; ++i) {
    l.push_back(i);
  }
  
  list<int>::iterator it = l.begin();
  while(l.size() > 1) {
    for(size_t i = 0; i < k; ++i) {
      if (++it == l.end()) {
        it = l.begin();
      }
    }

    it = l.erase(it);
    if (it == l.end()) {
      it = l.begin();
    }
  }
  
  return l.front();
}

int recursive(int n, int k) {
  int r = 0;
  for(size_t i = 2; i <= n; ++i) {
    r = (r + k) % i;
  }

  return r;
}

int recursive_two(int n, int k) {
  if (n == 1)
    return 0;
  else
    return (recursive_two(n - 1, k) + k) % n;
}

int main() {
  cout << "brute_force: " << brute_force(PEOPLE, STEP + 1) << endl;
  cout << "recursive: " << recursive(PEOPLE, STEP) << endl;
  cout << "recursive_two: " << recursive_two(PEOPLE, STEP) << endl;

  return 0;
}
