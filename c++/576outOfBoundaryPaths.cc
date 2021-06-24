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
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
    const int dirs[] = {-1, 0, 1, 0, -1};
    for (int move = 1; move <= maxMove; ++move)
      for (int row = 0; row < m; ++row)
        for (int col = 0; col < n; ++col)
          for (int dir = 0; dir < 4; ) {
            int nrow = row + dirs[dir],
                ncol = col + dirs[++dir];
            if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n)
              dp[move][row][col] += 1;
            else
              dp[move][row][col] = (dp[move][row][col] + dp[move - 1][nrow][ncol]) % kMod;
          }
    return dp[maxMove][startRow][startColumn];
  }
};

int main() {
  Solution s;
  
  return 0;
}
