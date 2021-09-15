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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1
class Solution {  // 65 ms
 public:
  int countSquares(vector<vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix.front().size();
    int dp[m][n];  // dp[i][j]: side length of largest mat square with bottom right vertex at (i, j)
    memset(dp, 0, sizeof dp);

    int res = 0;
    for (int i = 0; i < m; ++i) res += dp[i][0] = matrix[i][0];
    for (int j = 1; j < n; ++j) res += dp[0][j] = matrix[0][j];

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j])
          dp[i][j] = max(min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1, 1);
        res += dp[i][j];
      }
    return res;
  }
};

class Solution_OLD {  // 126 ms
 public:
  int countSquares(vector<vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp (m, vector<int> (n));
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        dp[i][j] = matrix[i][j];
        if (i && j && dp[i][j])
          dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
        res += dp[i][j];
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
