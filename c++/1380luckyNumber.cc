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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= n, m <= 50
// 1 <= matrix[i][j]
// minimum element in its row and maximum in its column
class Solution {
 public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> res;
    const int m = matrix.size(), n = matrix[0].size();
    vector<int> row_min (m, INT_MAX);
    vector<int> col_max (n, INT_MIN);
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        row_min[i] = min(row_min[i], matrix[i][j]);
        col_max[j] = max(col_max[j], matrix[i][j]);
      }
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j])
          res.push_back(matrix[i][j]);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
