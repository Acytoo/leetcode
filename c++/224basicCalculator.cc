#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
/*
  a stack of weather a - is before the (
  true for + and false for -
*/

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();

class Solution {
 public:
  int calculate(string s) {
    int i = 0, pos = 0, num = 0, res = 0;
    bool op = true, preOp = true;
    stack<bool> syms;
    syms.push(true);
    while (i < s.size()) {
      if (s[i] == ' ') {
        i++;
        continue;
      }

      if (s[i] > 47 && s[i] < 58) {
      	pos=i;
      	while(i < s.size() && isdigit(s[i])) i++;
      	num = stoi(s.substr(pos,i));
        if (op)
          res += num;
        else
          res -= num;
        continue;
      }
      if (s[i] == '+') {
        op = syms.top();
        preOp = true;
        i++;
        continue;
      }
      if (s[i] == '-') {
        op = !syms.top();
        preOp = false;
        i++;
        continue;
      }
      if (s[i] == '(') {
        if (i > 0 && !preOp)
          syms.push(!syms.top());
        else syms.push(syms.top());
        i++;
        continue;
      }
      if (s[i] == ')') { // ')'
        syms.pop();
        i++;
      }
    }
    return res;
  }
};

class Solution1 {
 public:
  int calculate(string s) {
    int i = 0, pos = 0, num = 0, res = 0;
    bool op = true, preOp = true;
    stack<bool> syms;
    syms.push(true);
    while (i < s.size()) {
      if (isspace(s[i])) {
        i++;
      } else if (isdigit(s[i])) {
      	pos=i;
      	while(i < s.size() && isdigit(s[i])) i++;
      	num = stoi(s.substr(pos,i));
        if (op)
          res += num;
        else
          res -= num;
      } else if (s[i] == '+') {
        op = syms.top();
        preOp = true;
        i++;
      } else if (s[i] == '-') {
        op = !syms.top();
        preOp = false;
        i++;
      } else if (s[i] == '(') {
        if (i > 0 && !preOp)
          syms.push(!syms.top());
        else syms.push(syms.top());
        i++;
      } else if (s[i] == ')') { // ')'
        syms.pop();
        i++;
      }
    }
    return res;
  }
};



int main() {
  string a = "(1+(4+5+2)-3)+(6+9)";//23
  Solution s;
  cout << s.calculate(a) << endl;
  return 0;
}
