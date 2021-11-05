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

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// 1 <= m * n <= 20
// -1 <= grid[i][j] <= 2

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    int ob = 1, res = 0;
    int sx = -1, sy = -1;
    function<int(int, int, int)> helper =
        [&] (const int x, const int y, int ob) -> int {
          if (x < 0 || x >= m || y < 0 || y >= n) return 0;
          if (grid[x][y] == -1) return 0;
          if (grid[x][y] == 2) return ob == 0;
          grid[x][y] = -1;
          int res = helper(x + 1, y, --ob)
                    + helper(x - 1, y, ob)
                    + helper(x, y + 1, ob)
                    + helper(x, y - 1, ob);
          grid[x][y] = 0;
          return res;
        };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0) ++ob;
        else if (grid[i][j] == 1) { sx = i; sy = j; }
    return helper(sx, sy, ob);
  }
};

class Solution_SAME {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    constexpr int dirs[] = {0, -1, 0, 1, 0};
    int empty = 1, res = 0;  // 1 is not obstacle
    int startx = -1, starty = -1;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++empty;
        } else if (grid[i][j] == 1) {
          startx = i;
          starty = j;
        }
      }
    function<void(int, int, int)> helper = [&] (const int x, const int y, const int empty) {
      if (x < 0 || x >= m || y < 0 || y >= n) return;
      if (grid[x][y] == -1) return;
      if (grid[x][y] == 2) {
        if (empty == 0) ++res;
        return;
      }
      if (grid[x][y] == 3) return;
      // 0 or 1
      grid[x][y] = 3;
      for (int i = 0; i < 4; ) {
        const int nx = x + dirs[i];
        const int ny = y + dirs[++i];
        helper(nx, ny, empty - 1);
      }
      grid[x][y] = 0;
    };
    helper(startx, starty, empty);
    return res;
  }
};



// search
class Solution_WA {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    int res = 0;
    int startx = -1, starty = -1;
    constexpr int dirs[] = {0, -1, 0, 1, 0};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          startx = i;
          starty = j;
          break;
        }
      // since m and n is not big, no break here seems faster
      // if (startx != -1) break;
    }
    auto check = [&] () {
      cout << "check" << endl;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          cout << grid[i][j] << " " ;
        cout << endl;
      }
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 0)
            return false;
      ++res;
      return true;
    };
    function<void(int, int)> helper = [&] (const int x, const int y) {
      if (x < 0 || x >= m || y < 0 || y >= n) return;
      if (grid[x][y] == -1) return;
      if (grid[x][y] == 2) check();
      if (grid[x][y] == 3) return;
      grid[x][y] = 3;
      for (int i = 0; i < 4; ) {
        const int nx = x + dirs[i];
        const int ny = y + dirs[++i];
        helper(nx, ny);
      }
      grid[x][y] = 0;
    };
    helper(startx, starty);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
