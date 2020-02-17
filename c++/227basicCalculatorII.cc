#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int calculate(string s) {
    int res = 0, prev = 0;
    char op = '+';
    for(int i=0, stop=s.size(); i<stop; ++i) {
      if (s[i]==' ')
        continue;

      if (isdigit(s[i])) {
        long num = 0;
        while (isdigit(s[i])) {
          num = num * 10 + s[i] - '0';
          ++i;
        }
        --i;
        switch (op) {
          case '+': res += prev, prev = num; break;
          case '-': res += prev, prev = -num; break;
          case '*': prev *= num; break;
          case '/': prev /= num; break;
          default: break;
        }
      } else {
        op = s[i];
      }
    }
    return res + prev;
  }
};

class Solution1 {
 public:
  int calculate(string s) {
    int num1 = 0;
    char op = '+';  // operation for current num(num1)
    stack<int> nums;
    int i = -1, n = s.size();
    while (++i < n) {
      if (s[i] == ' ')
        continue;

      if ('0' <= s[i]) {  // ascii(ops) < ascii(0)
        num1 = getNum(s, i, n);
      }

      if (op == '+') {  // new operator
        nums.push(num1);
      } else if (op == '-') {
        nums.push(-num1);
      } else if (op == '*') {  // * or /
        int tmp = num1 * nums.top();
        nums.pop();
        nums.push(tmp);
      } else if (op == '/') {
        int tmp = nums.top() / num1;
        nums.pop();
        nums.push(tmp);
      }

      if (i < n) {  // new operator
        op = s[i];
        num1 = 0;
      }
    }

    int res = 0;
    while (!nums.empty()) {
      res += nums.top();
      nums.pop();
    }
    return res;
  }
 private:
  int getNum(const string& s, int& idx, int& n) {
    int num = 0;
    while (idx<n && '0'<=s[idx]) {
      num = num * 10 + s[idx] - '0';
      ++idx;
    }
    return num;
  }
};

int main() {
  Solution s;
  
  return 0;
}
