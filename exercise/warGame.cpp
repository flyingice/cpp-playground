#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
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
void initVec(ifstream& stream, vector<int>& v) {
  if (stream) {
    size_t nb;
    stream >> nb;
    for (size_t i = 0; i < nb; ++i) {
      int x;
      if (stream >> x) v.push_back(x);
    }
  }
}

void init(vector<int>& a, vector<int>& b) {
  ifstream infile("input");

  if (infile) {
    a.clear();
    b.clear();

    initVec(infile, a);
    initVec(infile, b);
  }
}

/*
 * Return true if both parties have next available card, otherwise return false.
 */
bool fetchNextCard(list<int>& playerA, int& cardA, list<int>& playerB, int& cardB) {
  if (!playerA.empty() && !playerB.empty()) {
    cardA = playerA.front();
    cardB = playerB.front();
    playerA.pop_front();
    playerB.pop_front();
    return true;
  }

  return false;
}

void keepCardAside(list<int>& playerATmp, int cardA, list<int>& playerBTmp, int cardB) {
  playerATmp.push_back(cardA);
  playerBTmp.push_back(cardB);
}

/*
 * Return true if the round can be finished, otherwise return false.
 */
bool playNextRound(
    list<int>& playerA, list<int>& playerATmp, int& a, list<int>& playerB, list<int>& playerBTmp, int& b) {
  if (fetchNextCard(playerA, a, playerB, b)) {
    keepCardAside(playerATmp, a, playerBTmp, b);
    return true;
  }

  return false;
}

string play(const vector<int>& deckA, const vector<int>& deckB) {
  list<int> playerA, playerB;
  copy(deckA.begin(), deckA.end(), back_inserter(playerA));
  copy(deckB.begin(), deckB.end(), back_inserter(playerB));

  size_t turn = 0;
  int a = -1, b = -1;  // init value doesn't matter
  list<int> playerATmp, playerBTmp;
  while (!playerA.empty() && !playerB.empty()) {
    ++turn;

    if (!playNextRound(playerA, playerATmp, a, playerB, playerBTmp, b)) break;

    while (a == b) {  // a war
      // If one player is run out of card during a war, it is considered to be a draw.
      if (!(playNextRound(playerA, playerATmp, a, playerB, playerBTmp, b)
            && playNextRound(playerA, playerATmp, a, playerB, playerBTmp, b))) {
        return "Draw " + to_string(turn);
      }
    }

    if (a < b) {
      copy(playerBTmp.begin(), playerBTmp.end(), back_inserter(playerB));
      copy(playerATmp.begin(), playerATmp.end(), back_inserter(playerB));
    }
    else {
      copy(playerATmp.begin(), playerATmp.end(), back_inserter(playerA));
      copy(playerBTmp.begin(), playerBTmp.end(), back_inserter(playerA));
    }

    playerATmp.clear();
    playerBTmp.clear();
  }

  return (playerA.empty() ? "2 " : "1 ") + to_string(turn);
}

int main() {
  vector<int> playerA, playerB;
  init(playerA, playerB);
  cout << play(playerA, playerB) << endl;

  return 0;
}
