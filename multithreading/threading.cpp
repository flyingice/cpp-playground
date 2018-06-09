#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;

void fork_and_join() {
  cout << "fork_and_join:" << endl;

  thread t([]() {  // lambda
    cout << "Hello from thread!\n";
  });

  cout << "Hello from main!\n";

  // main thread waits for the child thread to finish
  // otherwise chlid thread might be destroyed prematurely when main exits
  t.join();
}

void fork_multiple_and_join() {
  cout << "fork_multiple_and_join:" << endl;

  static const int NUM = 10;
  vector<thread> v;
  for (int i = 0; i < NUM; ++i) {
    v.push_back(thread([]() { cout << "Hello from thread!\n"; }));
  }

  cout << "Hello from main!\n";

  for_each(v.begin(), v.end(), [](thread& t) { t.join(); });
  /* equivalent to
  for(int i = 0; i < NUM; ++i) {
    v[i].join();
  }
  */
}

int main() {
  fork_and_join();
  fork_multiple_and_join();

  return 0;
}
