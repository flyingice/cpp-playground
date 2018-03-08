#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int find_brute_force(const string& s, const string& t) {
  int i = 0, j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      ++i, ++j;
    } else {
      i = i - j + 1, j = 0;
    }
  }

  if (j >= t.size()) {
    return i - j;
  } else {
    return -1;
  }
}

int find_kmp(const string& s, const string& t) {
  // pattern pre-process to find the longest prefix
  int* ref = new int[t.size()];
  ref[0] = -1;
  for(size_t i = 1; i < t.size(); ++i) {
    int r = ref[i - 1];
    while (r != -1 && t[i] != t[r + 1]) {
      r = ref[r];
    }
    if (t[i] == t[r + 1]) {
      ref[i] = r + 1;
    } else {
      ref[i] = -1;
    }
  }

  /*
  ostream_iterator<int> out(cout, " ");
  copy(ref, ref + t.size(), out);
  cout << endl;
  */

  int i = 0, j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      ++i, ++j;
    } else {
      if (j == 0) {
        ++i;
      } else {
        j = ref[j - 1] + 1;
      }
    }
  }

  delete [] ref;
  
  if (j >= t.size()) {
    return i - j;
  } else {
    return -1;
  }
}

void string_match(const string& s, const string& t) {
  cout << "brute force: " << find_brute_force(s, t) << endl;
  cout << "find_kmp: " << find_kmp(s, t) << endl;
}

int main() {
  string_match("abcabcabcd", "abcabcd");
  string_match("xyxxyxyxyyxyxyxyyxyxyxx", "xyxyyxyxyxx");

  return 0;
}
