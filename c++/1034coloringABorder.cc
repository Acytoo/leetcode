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
#include <numeric>>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    const int m = grid.size(), n = grid[0].size(), origin = grid[r0][c0];
    vector<vector<int>> border (m, vector<int> (n));
    vector<int> dirs = {0, 1, 0, -1, 0};

    function<bool(int, int)> dfs =
        [&] (int x, int y) {
          if (x<0 || x==m || y<0 || y==n || grid[x][y]!=origin) return true;
          if (border[x][y] != 0) return false;
          border[x][y] = -2;
          bool is_border = false;
          for (int i=0; i<4; )
            is_border |= dfs(x+dirs[i], y+dirs[++i]);
          if (is_border) border[x][y] = -1;
          return false;
        };

    dfs(r0, c0);
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (border[i][j] == -1)
          grid[i][j] = color;

    return grid;
  }
};

int main() {
  Solution s;
  
  return 0;
}
