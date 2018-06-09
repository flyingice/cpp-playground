#include <iostream>
#include <string>
#include <thread>
#include <future>
using namespace std;

void funcByMove(promise<string>&& prms) {  // '&&' to match move semantics
  string s("Hello from futureByMove!");
  prms.set_value(s);
}

void funcByRef(promise<string>& prms) {
  string s("Hello from futureByRef!");
  prms.set_value(s);
}

string func() {
  string s("Hello from future!");
  return s;
}

int main() {
  promise<string> prms1;
  future<string> ftr1 = prms1.get_future();
  thread t1(&funcByMove, move(prms1));  // move semantic
  cout << "Hello from main!\n";
  // main thread will be blocked on the future until it is signaled
  string s1 = ftr1.get();
  cout << s1 << endl;
  t1.join();

  // The effect of the following code is the same as the one above
  promise<string> prms2;
  future<string> ftr2 = prms2.get_future();
  thread t2(&funcByRef, ref(prms2));  // pass by reference
  cout << "Hello from main!\n";
  string s2 = ftr2.get();
  cout << s2 << endl;
  t2.join();

  // The following does exactly the same thing using the grammar sugar
  auto ftr = async(&func);
  cout << "Hello from main!\n";
  string s = ftr.get();
  cout << s << endl;

  return 0;
}
