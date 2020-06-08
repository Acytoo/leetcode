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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    if (m == 0) return 0;
    const int n = obstacleGrid.front().size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1) return 0;

    vector<vector<int>> dp (m, vector<int> (n));
    for (int i = 0; i < m; ++i)
      if (obstacleGrid[i][0] == 0)
        dp[i][0] = 1;
      else
        break;

    for (int i = 1; i < n; ++i)
      if (obstacleGrid[0][i] == 0)
        dp[0][i] = 1;
      else
        break;


    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (obstacleGrid[i][j] == 1)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp.back().back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
