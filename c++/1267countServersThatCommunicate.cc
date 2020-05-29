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
  int countServers(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    function<void(int, int)> dfs =
        [&] (const int x, const int y) {
          bool connected = false;
          for (int i = 0; i < m; ++i)
            if (grid[i][y] == 1) {
              if (i == x) continue;
              grid[i][y] = 2;
              connected = true;
              dfs(i, y);
            }
          for (int j = 0; j < n; ++j)
            if (grid[x][j] == 1) {
              if (j == y) continue;
              grid[x][j] = 2;
              connected = true;
              dfs(x, j);
            }
          if (connected) grid[x][y] = 2;
        };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          dfs(i, j);
          break;
        }
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        res += (grid[i][j] == 2);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
