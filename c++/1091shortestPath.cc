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
// N x N size matrix
class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size() - 1;
    if (grid[0][0] == 1 || grid[n][n] == 1)
      return -1;
    int directions[8][2] = {{1,0}, {0,1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {-1,0}, {0,-1}};
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    grid[0][0] = 1;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      int x = cur.first.first, y = cur.first.second, dis = cur.second;
      if (x == n && y == n)
        return dis;
      for (auto dir: directions) {
        int nx = x+dir[0], ny = y+dir[1];
        if (nx<0 || nx>n || ny<0 || ny>n || grid[nx][ny]==1)
          continue;
        q.push({{nx, ny}, dis+1});
        grid[nx][ny] = 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
