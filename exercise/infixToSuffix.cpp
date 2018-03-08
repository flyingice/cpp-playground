#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

struct Operator {
  Operator(char ic): c(ic) {
    switch(c) {
      case '+':
      case '-':
        p = 1; break;
      case '*':
      case '/':
        p = 2; break;
      case '^':
        p = 3; break;
      default:
        p = 0; break;
    }
  }

  virtual ~Operator() {};

  char c;
  int p;
};

void print(const stack<Operator>& s) {
  stack<Operator> cs(s);
  while(!cs.empty()) {
    cout << cs.top().c << " ";
    cs.pop();
  }

  cout << endl;
}

string convertToSuffix(const string& infix) {
  stack<Operator> s;
  string result;
  for(size_t i = 0; i < infix.size(); ++i) {
    if (::isdigit(infix[i])) {  // operand
      result += infix[i];
    } else {  // operator
      Operator op(infix[i]);
      
      if (s.empty()) {
        s.push(op); continue;
      }

      if (infix[i] == '(') {
        s.push(op);
      } else if(infix[i] == ')') {
        while(!s.empty() && s.top().c != '(') {
          result += s.top().c;
          s.pop();
        }

        if(!s.empty()) s.pop(); // pop the matching '(' from the stack
      } else if (infix[i] == '^' && s.top().p == op.p) {
        s.push(op); // chained ^ are evaluated from right to left
      } else if (s.top().p < op.p) {
        s.push(op); // operators with higher precedence might appear later on
      } else {
        while(!s.empty() && s.top().p >= op.p) {
          result += s.top().c;
          s.pop();
        }

        s.push(op);
      }
    }
  }

  // pop the remaining operators in the stack
  while(!s.empty()) {
    result += s.top().c;
    s.pop();
  }

  return result;
}

int main() {
  string infix = "1-2^3^3-(4+5*6)*7";
  cout << convertToSuffix(infix) << endl; // expected output: 1233^^-456*+7*-
  return 0;
}
