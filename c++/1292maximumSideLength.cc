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

// DP, 1 <= m, n <= 300
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    const int m = mat.size(), n = mat.front().size();
    vector<vector<int>> sum (m + 1, vector<int> (n + 1));  // sum
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + mat[i - 1][j - 1];

    int res = 0;
    auto squareSum =
        [&] (int x0, int y0, int x1, int y1) {  // top-left : bottom-right
          return sum[x1][y1] - sum[x0 - 1][y1] - sum[x1][y0 - 1] + sum[x0 - 1][y0 - 1];
        };
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        for (int k = 1; i + k <= m && j + k <= n; ++k)
          if (squareSum(i, j, i + k, j + k) <= threshold)
            res = max(res, k + 1);
    return res;
  }
};

class Solution_WRONG {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    const int m = mat.size(), n = mat.front().size();
    vector<vector<int>> sum (m, vector<int> (n));  // sum
    sum[0][0] = mat[0][0];
    for (int i = 1; i < m; ++i) sum[i][0] = sum[i - 1][0] + mat[i][0];
    for (int i = 1; i < n; ++i) sum[0][i] = sum[0][i - 1] + mat[0][i];
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + mat[i][j];

    int res = 0;
    auto squareSum =
        [&] (int x0, int y0, int x1, int y1) {  // top-left : bottom-right
          return sum[x1][y1] - sum[x0 - 1][y1] - sum[x1][y0 - 1] + sum[x0 - 1][y0 - 1]; // WRONG, x0 - 1 might < 0
        };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 1; i + k < m && j + k < n; ++k)
          if (squareSum(i, j, i + k, j + k) <= threshold)
            res = max(res, k);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
