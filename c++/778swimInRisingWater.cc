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
// From huahua
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size(), nn = n - 1;
    priority_queue<pair<int, int>> pq;  // {-time, y * N + x}
    pq.push({-grid[0][0], 0});
    bool seen[n * n];
    memset(seen, 0, sizeof seen);
    constexpr int dirs[] = {-1, 0, 1, 0, -1};
    seen[0] = true;
    while (!pq.empty()) {
      auto node = pq.top(); pq.pop();
      int t = -node.first;
      int x = node.second % n;
      int y = node.second / n;
      if (x == nn && y == nn) return t;
      for (int dir = 0; dir < 4; ) {
        int tx = x + dirs[dir],
            ty = y + dirs[++dir];
        if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
        if (seen[ty * n + tx]) continue;
        seen[ty * n + tx] = true;
        pq.push({-max(t, grid[tx][ty]), ty * n + tx});
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
