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
// Brute force, or you can call it simulation
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    int res = 0;
    bool rot = false, still_fresh = false;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> will_rot;
    do {
      rot = false;
      still_fresh = false;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) {
          if (grid[i][j] == 2) {  // This one rotten and will try to affect others
            for (const auto &dir: dirs) {
              int x = i + dir[0], y = j + dir[1];
              if (x<0 || x==m || y<0 || y==n) continue;
              if (grid[x][y] == 1) {
                will_rot.emplace_back(initializer_list<int>{x, y});
                // grid[x][y] = 2;
                rot = true;
              }
            }
          } else if (grid[i][j] == 1) {
            still_fresh = true;
          }
        }
      for (const auto &xy: will_rot)
        grid[xy[0]][xy[1]] = 2;
      will_rot.clear();
      if (rot) ++res;
    } while (rot);
    return still_fresh? -1: res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
