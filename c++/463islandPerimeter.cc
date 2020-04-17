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
  int islandPerimeter(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    int res = 0;
    vector<int> dirs = {0, 1, 0, -1, 0};
    function<int(int, int)> checkNeighbor =
        [&] (int x, int y) {
          int res = 0;
          for (int i=0; i<4; ) {
            int new_x = x+dirs[i], new_y = y+dirs[++i];
            if (new_x<0 || new_x==m || new_y<0 || new_y==n || grid[new_x][new_y]==0) continue;
            ++res;
          }
          return 4-res;
        };
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j])
          res += checkNeighbor(i, j);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
