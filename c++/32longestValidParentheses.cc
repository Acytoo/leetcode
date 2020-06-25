#include <iostream>
#include <sstream>
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
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    int res = 0, start = 0;
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        if (stk.empty()) {
          start = i + 1;
        } else {
          stk.pop();
          res = max(res, stk.empty()? i - start + 1: i - stk.top());
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
