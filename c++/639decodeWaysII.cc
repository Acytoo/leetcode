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
// 1 <= s.length <= 105
// s[i] is a digit or '*'.
// From huahua
class Solution {
 public:
  int numDecodings(string_view s) {
    constexpr int KMod = 1e9 + 7;
    auto one = [&] (char c) -> int {
      if (c == '0') return 0;
      if (c == '*') return 9;
      return 1;
    };
    auto two = [&] (char c1, char c2) -> int {
      if (c1 == '*') {
        if (c2 == '*') return 15;  // 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26
        return c2 <= '6' ? 2 : 1;
      } else if (c2 == '*') {
        switch (c1) {
          case '1': return 9;
          case '2': return 6;
          default: return 0;
        }
      } else {
        const int num = (c1 - '0') * 10 + c2 - '0';
        return num >= 10 && num <= 26;
      }
    };

    long dp[2] = {1, one(s[0])};
    for (int i = 1, n = s.size(); i < n; ++i) {
      long tmp = one(s[i]) * dp[1] + two(s[i - 1], s[i]) * dp[0];
      tmp %= KMod;
      dp[0] = dp[1];
      dp[1] = tmp;
    }
    return dp[1];
  }
};

int main() {
  Solution s;
  
  return 0;
}
