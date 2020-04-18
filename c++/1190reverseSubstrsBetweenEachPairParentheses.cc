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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string reverseParentheses(string s) {
    stack<string> stk;
    stk.push("");
    for (const char c: s) {
      if (c == '(') {
        stk.push("");
      } else if (c != ')') {
        stk.top() += c;
      } else {
        string str = stk.top(); stk.pop();
        stk.top().insert(stk.top().end(), str.rbegin(), str.rend());
      }
    }
    return stk.top();
  }
};

int main() {
  Solution s;
  cout << s.reverseParentheses("(ed(et(oc))el)") << endl;
  return 0;
}
