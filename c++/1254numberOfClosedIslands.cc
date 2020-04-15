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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// This time island is 0
class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    vector<int> dirs = {0, 1, 0, -1, 0};
    function<bool(int, int)> dfs =
        [&] (int x, int y) {
          if (x < 0 || x == m || y < 0 || y == n) return false;
          if (grid[x][y]++) return true;
          bool island = true;
          for (int i=0; i<4; )
            island &= dfs(x+dirs[i], y+dirs[++i]);
          return island;
        };
    int res = 0;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j] == 0 && dfs(i, j))
          ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
