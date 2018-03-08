#include <iostream>
#include <string>
using namespace std;

// fake function to simulate the library function asciiArt::toGraphic
string toGraphic(char c) {
  string result = "*";
  for (size_t i = 0; i < c - 'A'; ++i) {
    result += "*";
  }

  return result;
}

char toChar(const string& s) {
  // table to store the graphic representation of the char
  static const size_t NB = 26;
  string table[NB];
  for(size_t i = 0; i < NB; ++i) {
    table[i] = toGraphic('A' + i);
  }

  // map the graphic representation back to the char
  int index = -1;
  for(size_t i = 0; i < NB; ++i) {
    if (table[i] == s) {
      index = i; break;
    }
  }

  if (index == -1)
    return '?';
  else
    return char('A' + index);
}

int main() {
  // test cases
  cout << toChar("***") << endl; // print 'C'
  cout << toChar("*******************") << endl;  // print 'S'
  return 0;
}
