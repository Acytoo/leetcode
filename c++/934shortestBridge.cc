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
  int shortestBridge(vector<vector<int>>& A) {
    const int n = A.size();
    queue<pair<int, int>> q;
    constexpr int dirs[5] = {0, -1, 0, 1, 0};
    function <void(int, int)> dfs =
        [&] (const int x, const int y) {
          if (x < 0 || x >= n || y < 0 || y >= n || A[x][y] != 1) return ;
          A[x][y] = 2;
          q.emplace(x, y);
          for (int i = 0; i < 4; )
            dfs(x + dirs[i], y + dirs[++i]);
        };

    bool found = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (A[i][j]) {
          dfs(i, j);
          found = true;
          break;
        }
      if (found) break;
    }

    int res = 0;
    while (!q.empty()) {
      int tmp = q.size();
      while (tmp--) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; ) {
          int x  = cur.first + dirs[i], y = cur.second + dirs[++i];
          if (x < 0 || x >= n || y < 0 || y >= n || A[x][y] == 2) continue ;
          if (A[x][y] == 1) return res;
          A[x][y] = 2;
          q.emplace(x, y);
        }
      }
      ++res;
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
