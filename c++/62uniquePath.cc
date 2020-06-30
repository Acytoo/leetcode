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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Fast solution from leetcode, math way
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    // Misnomer : This is actually arranging m-1 Ds with n-1 Rs
    long long mCn = 1;
    for (long long i = 1; i < n; ++i) {
      mCn *= (m - 1 + i);
      mCn /= i;
    }
    return mCn;
  }
};
// Bottom up DP
class Solution1 {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i=1; i < m; ++i)
      for (int j=1; j < n; ++j)
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
  }
};

int main() {
  Solution s;
  cout << s.uniquePaths(7, 3) << endl;
  return 0;
}
