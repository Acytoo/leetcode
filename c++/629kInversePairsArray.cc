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
  int kInversePairs(int n, int k) {
    const int kMod = 1e9 + 7;
    vector<vector<int>> dp (n + 1, vector<int> (k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = 1;
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % kMod;
        if (i <= j) dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + kMod) % kMod;
      }
    }
    return dp.back().back();
  }
};

class Solution_TLE {
 public:
  int kInversePairs(int n, int k) {
    const int kMod = 1e9 + 7;
    vector<vector<int>> dp (n + 1, vector<int> (k + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        for (int kk = 0; kk <= k; ++kk) {
          int diff = kk - j;
          if (0 <= diff && diff <= k)
            dp[i][kk] = (dp[i][kk] + dp[i - 1][diff]) % kMod;
        }
    return dp[n][k];
  }
};

int main() {
  Solution s;
  
  return 0;
}
