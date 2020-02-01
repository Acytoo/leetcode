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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (!rows) return 0;
    int cols = matrix[0].size();

    // int dp[rows][cols] = {{0}};
    vector<vector<int>> dp (rows, vector<int>(cols, 0));
    function<int(int, int)> dfs = [&] (int x, int y) {
                                    if (dp[x][y]) return dp[x][y];
                                    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0,-1}};
                                    for (auto &dir : dirs) {
                                      int xx = x + dir[0], yy = y + dir[1];
                                      if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
                                      if (matrix[xx][yy] <= matrix[x][y]) continue;
                                      dp[x][y] = max(dp[x][y], dfs(xx, yy));
                                    }
                                    return ++dp[x][y];
                                  };

    int res = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        res = max(res, dfs(i, j));
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
