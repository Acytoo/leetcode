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
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    constexpr int dirs[] = {-1, 0, 1, 0, -1};
    if (m == 0) return {};
    const int n = matrix.front().size();
    function<void(int, int, int, vector<vector<int>>&)> dfs =
        [&] (int x, int y, int h, vector<vector<int>> &ocean) {
          if (x < 0 || x >= m || y < 0 || y >= n ||
              ocean[x][y] || matrix[x][y] < h) return ;
          // can flow to xy
          ocean[x][y] = 1;
          for (int i = 0; i < 4; )
            dfs(x + dirs[i], y + dirs[++i], matrix[x][y], ocean);
        };
    vector<vector<int>> pac (m, vector<int> (n)), atl (m, vector<int> (n));
    for (int i = 0, j = n - 1; i < m; ++i) {
      dfs(i, 0, 0, pac);
      dfs(i, j, 0, atl);
    }
    for (int j = 0, i = m - 1; j < n; ++j) {
      dfs(0, j, 0, pac);
      dfs(i, j, 0, atl);
    }
    vector<vector<int>> res;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (atl[i][j] && pac[i][j])
          res.emplace_back(initializer_list<int> {i, j});
    return res;
  }
};

class Solution_WRONG {
  // [[1,2,3],[8,9,4],[7,6,5]] : 6 -> 5 -> 4 -> 3 -> Pacific
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> res;
    const int m = matrix.size();
    if (m == 0) return res;
    const int n = matrix.front().size();
    vector<vector<int>> pac (m, vector<int> (n));
    for (int i = 0; i < m; ++i) pac[i][0] = 1;
    for (int i = 1; i < n; ++i) pac[0][i] = 1;
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        pac[i][j] = (matrix[i][j] >= matrix[i - 1][j] && pac[i - 1][j]) ||
                    (matrix[i][j] >= matrix[i][j - 1] && pac[i][j - 1]);
    vector<vector<int>> atl (m, vector<int> (n));
    for (int i = m - 1, j = n - 1; i >= 0; --i) atl[i][j] = 1;
    for (int i = m - 1, j = n - 2; j >= 0; --j) atl[i][j] = 1;
    for (int i = m - 2; i >= 0; --i)
      for (int j = n - 2; j >= 0; --j)
        atl[i][j] = (matrix[i][j] >= matrix[i + 1][j] && atl[i + 1][j]) ||
                    (matrix[i][j] >= matrix[i][j + 1] && atl[i][j + 1]);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (atl[i][j] && pac[i][j])
          res.emplace_back(initializer_list<int> {i, j});
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
