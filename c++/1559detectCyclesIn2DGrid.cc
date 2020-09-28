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
  bool containsCycle(vector<vector<char>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    constexpr int dirs[] = {0, 1, 0, -1, 0};
    vector<vector<int>> visited(m, vector<int>(n));
    function<bool(int, int, int, int)> dfs =
        [&] (const int x, const int y, const int px, const int py) {
          ++visited[x][y];
          for (int i = 0; i < 4; ) {
            const int xx = x + dirs[i], yy = y + dirs[++i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] != grid[x][y]) continue;
            if (visited[xx][yy] == 0) {
              if (dfs(xx, yy, x, y)) return true;
            } else {  // visited before
              if (xx != px && yy != py) return true;  // at least length of 4 if new x (xx) is not pre x (px)
            }
          }
          return false;
        };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (visited[i][j] == 0 && dfs(i, j, -1, -1))
          return true;
        visited[i][j] = 1;
      }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
