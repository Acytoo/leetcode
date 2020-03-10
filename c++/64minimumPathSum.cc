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
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0)
      return 0;
    int n = grid[0].size();
    for (int i=1; i<m; ++i)
      grid[i][0] += grid[i-1][0];
    for (int j=1; j<n; ++j)
      grid[0][j] += grid[0][j-1];

    for (int i=1; i<m; ++i)
      for (int j=1; j<n; ++j)
        grid[i][j] += min(grid[i-1][j], grid[i][j-1]);

    return grid[m-1][n-1];
  }
};

int main() {
  Solution s;
  
  return 0;
}
