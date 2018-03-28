#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<string> split(const string& s) {
  vector<string> v;
  
  string word;
  size_t i = 0;
  while(i < s.size()) {
    if(isspace(s[i])) {
       if(!word.empty()) {
          v.push_back(word);
          word.clear();
       }
    } else {
      word += s[i];
    }
    ++i;
  }

  if(!word.empty()) v.push_back(word);

  return v;
}

void reverse(vector<string>& v) {
  int i = 0, j = v.size() - 1;
  while(i < j) {
    if(v[i] != v[j]) swap(v[i], v[j]);
    ++i, --j;
  }
}

int main() {
  vector<string> v = split("Trump or Hillary");

  ostream_iterator<string> out(cout, " ");
  copy(v.begin(), v.end(), out);
  cout << endl;

  reverse(v);
  copy(v.begin(), v.end(), out);
  cout << endl;

  return 0;
}
