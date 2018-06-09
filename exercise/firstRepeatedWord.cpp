#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

bool isDelimeter(const char c) {
  static const string delimeters(" \t,.:;");
  return delimeters.find(c) != string::npos;
}

string findFirstRepeatedWord(const string& sentence) {
  unordered_set<string> word_counter;

  int sz = sentence.size();
  int i  = 0;
  while (i < sz) {
    while (i < sz && isDelimeter(sentence[i])) ++i;
    ostringstream os;
    while (i < sz && !isDelimeter(sentence[i])) os << sentence[i++];
    string word = os.str();
    if(!word.empty()) {
      if (word_counter.count(word)) return word;
      word_counter.insert(word);
    }
  }

  return "";
}

int main() {
  return 0;
}
