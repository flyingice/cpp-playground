#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

mutex mut;

int main() {
  static const int NUM = 5;
  vector<thread> v;
  for (int i = 0; i < NUM; i++) {
    v.push_back(thread([i]() {
      lock_guard<mutex> lk(mut);  // stdout is a shared resource
      cout << "Hello from thread " << i << endl;
    }));
  }

  for_each(v.begin(), v.end(), [](thread& t) { t.join(); });

  return 0;
}