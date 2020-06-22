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

// '*' Matches zero or more of the **preceding** element. => s = "b", p = "a*b" --> true
// Recustion
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    const int m = s.size(), n = p.size();
    function<bool(int, int)> helper =
        [&] (const int i, const int j) {
          if (j == n) return i == m;
          if (n - j > 1 && p[j + 1] == '*')
            return helper(i, j + 2) || (i != m && (s[i] == p[j] || p[j] == '.') && helper(i + 1, j));
          else
            return i != m && (s[i] == p[j] || p[j] == '.') && helper(i + 1, j + 1);
        };
    return helper(0, 0);
  }
};

class Solution_basic {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    if (p.size() > 1 && p[1] == '*')
      return isMatch(s, p.substr(2)) ||
          (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
    else
      return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
  }
};

int main() {
  Solution s;
  
  return 0;
}
