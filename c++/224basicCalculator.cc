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
// recursion
class Solution {
 public:
  int calculate(string s) {
    const int n = s.size();
    int pos = 0;
    function<int(int&)> eval = [&] (int &pos) {
      int cur = 0, res = 0;
      bool add = true;
      while (pos < n) {
        const char c = s[pos];
        if (isdigit(c)) {
          cur = cur * 10 + (c - '0');
          ++pos;
        } else if (c == '+' || c == '-') {
          if (add)
            res += cur;
          else
            res -= cur;
          cur = 0;
          add = c == '+';
          ++pos;
        } else if (c == '(') {
          cur = eval(++pos);
        } else if (c == ')') {
          ++pos;
          break;
        } else {  // c == ' '
          ++pos;
        }
      }
      return add ? res + cur : res - cur;
    };
    return eval(pos);
  }
};

class Solution_WA {
  // 旧代码改改风格重写，但是我已经看不懂了
  // 这套代码显然有问题，但是i第一遍过了
  // 然后也是 MLE ……
 public:
  int calculate(string s) {
    const int n = s.size();
    int i = 0, pos = 0, num = 0, res = 0;
    bool op = true, preOp = true;
    stack<bool> syms;  // only + and -, so +: true; -: false
    syms.push(true);
    while (i < n) {
      if (s[i] == ' ') {
        ++i;
        continue;
      }
      if (s[i] >= '0' && s[i] <= '9') {  // isdigit()
      	pos = i;
      	while(i < n && isdigit(s[i])) ++i;
      	num = stoi(s.substr(pos,i));  // ??? substr(pos, len)
        if (op)
          res += num;
        else
          res -= num;
        continue;
      }
      if (s[i] == '+') {
        op = syms.top();
        preOp = true;
        ++i;
        continue;
      }
      if (s[i] == '-') {
        op = !syms.top();
        preOp = false;
        ++i;
        continue;
      }
      if (s[i] == '(') {
        if (i > 0 && !preOp)
          syms.push(!syms.top());
        else syms.push(syms.top());
        ++i;
        continue;
      }
      if (s[i] == ')') { // ')'
        syms.pop();
        ++i;
      }
    }
    return res;
  }
};

class Solution_OLD_WA {
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

class Solution1_OLD_WA {
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
