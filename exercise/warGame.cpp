#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

/*
example input file:
4
10
5
2
6
4
10
4
3
8
*/
void init(vector<int>& a, vector<int>& b) {
  ifstream infile("input");

  a.clear(); 
  b.clear();

  if(infile) {
    size_t nb;

    infile >> nb;
    for(size_t i = 0; i < nb; ++i) {
      int x;
      infile >> x;
      a.push_back(x);
    }

    infile >> nb;
    for(size_t i = 0; i < nb; ++i) {
      int y;
      infile >> y;
      b.push_back(y);
    }
  }
}

void fetchNextCard(deque<int>& a, deque<int>& b, int& a1, int& b1) {
  if (!a.empty() && !b.empty()) {
    a1 = a.front();
    b1 = b.front();
    a.pop_front();
    b.pop_front();
  } else {
    exit(1);
  }
}

void keepCardAside(vector<int>& aTmp, vector<int>& bTmp, int a1, int b1) {
  aTmp.push_back(a1);
  bTmp.push_back(b1);
}

string play(const vector<int>& deckA, const vector<int>& deckB) {
  deque<int> a, b;
  copy(deckA.begin(), deckA.end(), back_inserter(a));
  copy(deckB.begin(), deckB.end(), back_inserter(b));

  size_t turn = 0;
  vector<int> aTmp, bTmp;
  int a1, b1;
  while(a.size() && b.size()) {
    fetchNextCard(a, b, a1, b1);
    keepCardAside(aTmp, bTmp, a1, b1);

    while(a1 == b1) {
      // skip the next card
      fetchNextCard(a, b, a1, b1);
      keepCardAside(aTmp, bTmp, a1, b1);

      fetchNextCard(a, b, a1, b1);
      keepCardAside(aTmp, bTmp, a1, b1);
    }

    if(a1 < b1) {
      copy(bTmp.begin(), bTmp.end(), back_inserter(b));
      copy(aTmp.begin(), aTmp.end(), back_inserter(b));
    } else if (a1 > b1) {
      copy(aTmp.begin(), aTmp.end(), back_inserter(a));
      copy(bTmp.begin(), bTmp.end(), back_inserter(a));
    }

    aTmp.clear(); bTmp.clear();
    turn++;
  }

  ostringstream os;
  os << (a.size() > 0 ? "1" : "2") << " " << turn; 
  return os.str();
}

int main() {
  vector<int> a, b;
  init(a, b);

  ostream_iterator<int> out(cout, " ");
  copy(a.begin(), a.end(), out);
  cout << endl;
  copy(b.begin(), b.end(), out);
  cout << endl;

  cout << play(a, b) << endl;

  return 0;
}
