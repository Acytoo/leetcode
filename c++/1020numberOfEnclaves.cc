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
  int numEnclaves(vector<vector<int>>& A) {
    int res = 0;
    const int m = A.size()-1, n = A[0].size()-1;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    function<bool(int, int, int&)> dfs =
        [&] (int x, int y, int &cur) {
          if (x<0 || x>m || y<0 || y>n) return false;
          if (A[x][y] == 0) return true;
          ++cur;
          A[x][y] = 0;
          bool res = true;
          for (const auto &dir: dirs)
            res &= dfs(x+dir[0], y+dir[1], cur);
          return res;
        };

    for (int i=1; i<m; ++i)
      for (int j=1; j<n; ++j) {
        int cur = 0;
        if (dfs(i, j, cur)) res += cur;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
