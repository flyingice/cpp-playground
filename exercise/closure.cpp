#include <iostream>
using namespace std;

// c++14 new feature, required to be compiled with the option -std=c++14
auto adder() {
  int sum = 0;
  return [=](int value) mutable {
    sum += value;
    return sum;
  };
}

int main() {
  auto f = adder();
  for(int i = 0; i < 10; ++i) cout << f(i) << endl;

  return 0;
}
