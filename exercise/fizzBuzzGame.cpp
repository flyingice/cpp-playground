#include <iostream>
#include <string>
using namespace std;

/*
 * output Fizz for multiples of three, Buzz for multiples of five
 * and FizzBuzz for multiples of both three and five
 */
string fizzBuzz1(int n) {
  if (n % 3 == 0 && n % 5 == 0) {
    return "FizzBuzz";
  }
  else if (n % 3 == 0) {
    return "Fizz";
  }
  else if (n % 5 == 0) {
    return "Buzz";
  }
  else {
    return to_string(n);
  }
}

/*
 * add a new rule: output Foo for multiples of seven
 */
string fizzBuzz2(int n) {
  string res;
  if (n % 3 == 0) res += "Fizz";
  if (n % 5 == 0) res += "Buzz";
  if (n % 7 == 0) res += "Foo";

  return res.empty() ? to_string(n) : res;
}

int main() {
  for (int i = 0; i < 100; ++i) {
    cout << fizzBuzz2(i) << endl;
  }

  return 0;
}
