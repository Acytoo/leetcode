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
// This time 1 represents land
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    const int m = grid.size();
    if (m == 0) return 0;
    const int n = grid[0].size();
    if (n == 0) return 0;

    vector<int> dirs = {0, 1, 0, -1, 0};
    function<void(int, int)> dfs =
        [&] (int x, int y) {
          if (x<0 || x==m || y<0 || y==n || grid[x][y]=='0') return ;
          grid[x][y] = '0';
          for (int i=0; i<4; )
            dfs(x+dirs[i], y+dirs[++i]);
        };
    int res = 0;

    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j] == '1') {
          ++res;
          dfs(i, j);
        }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
