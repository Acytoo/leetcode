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
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0;
    const int m = grid.size(), n = grid[0].size();
    function<int(int, int)> dfs =
        [&] (int i, int j) {
          if (i<0 || i==m || j<0 || j==n || grid[i][j]<=0) return 0;
          grid[i][j] = -1;
          int above = dfs(i, j+1);
          int below = dfs(i, j-1);
          int left = dfs(i-1, j);
          int right = dfs(i+1, j);
          // grid[i][j] = 1;
          return above+below+left+right+1;
        };
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        int tmp = dfs(i, j);
        res = max(res, tmp);
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
