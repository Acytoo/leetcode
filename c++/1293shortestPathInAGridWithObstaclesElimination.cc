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
// BFS
class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    const int m = grid.size(), n = grid[0].size();
    vector<vector<int>> seen(m, vector<int> (n, INT_MAX));
    deque<tuple<int, int, int>> dq;  // x, y, number of obstacles
    constexpr int dirs[] = {-1, 0, 1, 0, -1};
    int steps = 0;
    dq.emplace_back(0, 0, 0);
    while (!dq.empty()) {
      int size = dq.size();
      while (size--) {
        int x, y, o;
        tie(x, y, o) = dq.front(); dq.pop_front();
        if (x == m - 1 && y == n - 1) return steps;
        for (int i = 0; i < 4; ){
          int nx = x + dirs[i];
          int ny = y + dirs[++i];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
          int no = o + grid[nx][ny];
          if (no >= seen[nx][ny] || no > k) continue;
          seen[nx][ny] = no;
          dq.emplace_back(nx, ny, no);
        }
      }
      ++steps;
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{1}};
  cout << s.shortestPath(a, 1) << endl;
  return 0;
}
