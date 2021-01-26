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
// DP, dp[i][j] = min(dp[i][j], dp[i - 1][j] + delta), all four directions
class Solution {
  //  From huahua
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    const int m = heights.size(), n = heights[0].size();
    constexpr int dirs[] = {0, -1, 0, 1, 0};
    int dp[10001];
    memset(dp, CHAR_MAX, sizeof dp);
    dp[0] = 0;
    bool changed = false;
    do {
      changed = false;
      for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
          for (int d = 0; d < 4; ) {
            const int nr = r + dirs[d],
                      nc = c + dirs[++d];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            const int ndp = max(dp[nr * 100 + nc], abs(heights[nr][nc] - heights[r][c]));
            if (ndp < dp[r * 100 + c]) {
              dp[r * 100 + c] = ndp;
              changed = true;
            }
          }
    } while (changed);
    return dp[(m - 1) * 100 + n - 1];
  }
};

int main() {
  Solution s;
  
  return 0;
}
