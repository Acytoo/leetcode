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

// Dead position: (1, -1), (1, wall), (-1, wall)

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    vector<int> res;
    const int m = grid.size(), n = grid[0].size();
    auto fall = [&] (int j) ->int {
      for (int i = 0; i < m; ++i)
        if (grid[i][j] == -1) {
          if (j == 0 || grid[i][j - 1] == 1) return -1;
          --j;
        } else {  // 1
          if (j == n - 1 || (j + 1 < n && grid[i][j + 1] == -1)) return -1;
          ++j;
        }
      return j;
    };
    for (int i = 0; i < n; ++i) res.emplace_back(fall(i));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
