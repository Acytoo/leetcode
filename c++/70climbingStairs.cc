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
  int climbStairs(int n) {
    if (n < 3) return n;
    int dp1 = 1, dp2 = 2;
    for (int i = 3; i <= n; ++i) {
      const int tmp = dp2;
      dp2 += dp1;
      dp1 = tmp;
    }
    return dp2;
  }
};

class Solution_SAME {
 public:
  int climbStairs(int n) {
    if (n < 3) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
      dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }
};

int main() {
  Solution s;
  
  return 0;
}
