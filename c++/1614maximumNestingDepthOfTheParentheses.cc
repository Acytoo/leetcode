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
  int maxDepth(string s) {
    int res = 0, cur = 0;
    for_each(s.begin(), s.end(), [&] (const char c) {
      if (c == '(')
        res = max(++cur, res);
      else if (c == ')')
        --cur;
    });
    return res;
  }
};

class Solution2 {
 public:
  int maxDepth(string s) {
    int res = 0, cur = 0;
    for (const char c: s)
      if (c == '(')
        res = max(++cur, res);
      else if (c == ')')
        --cur;
    return res;
  }
};

class Solution1 {
 public:
  int maxDepth(string s) {
    int res = 0, cur = 0;
    for (const char c: s) {
      if (c == '(') {
        ++cur;
        res = max(cur, res);
      } else if (c == ')') {
        --cur;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
