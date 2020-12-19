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
// DP, from huahua
class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int R = grid.size(), C = grid[0].size();
    vector<vector<vector<int>>> dp (R, vector<vector<int>> (C, vector<int> (C, -1)));
    function<int(int, int, int)> helper = [&] (int r, int c1, int c2) {
      if (r < 0 || r >= R || c1 < 0 || c1 >= C || c2 < 0 || c2 >= C) return 0;
      int &res = dp[r][c1][c2];
      if (res != -1) return res;
      const int cur = grid[r][c1] + ((c1 == c2)? 0: grid[r][c2]);
      for (int d1 = -1; d1 <= 1; ++d1)
        for (int d2 = -1; d2 <= 1; ++d2)
          res = max(res, cur + helper(r + 1, c1 + d1, c2 + d2));
      return res;
    };
    return helper(0, 0, C - 1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
