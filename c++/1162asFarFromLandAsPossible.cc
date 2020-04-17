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
// BFS
class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j])
          q.emplace(make_pair(i, j));
    vector<int> dirs {0, 1, 0, -1, 0};
    int res = -1, cur = 0;

    while (!q.empty()) {
      int t = q.size();
      while (t--) {
        auto p = q.front(); q.pop();
        int x = p.first, y = p.second;
        if (grid[x][y] == 2) res = max(res, cur);
        for (int i=0; i<4; ) {
          int new_x = x+dirs[i], new_y = y+dirs[++i];
          if (new_x<0 || new_x==m || new_y<0 || new_y==n || grid[new_x][new_y]!=0) continue;
          grid[new_x][new_y] = 2;
          q.emplace(make_pair(new_x, new_y));
        }
      }
      ++cur;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
