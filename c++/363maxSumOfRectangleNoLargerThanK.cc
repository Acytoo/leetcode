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

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -100 <= matrix[i][j] <= 100
// -105 <= k <= 105

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    const int r = matrix.size(), c = matrix[0].size();
    int res = INT_MIN;
    vector<vector<int>> sum (r + 1, vector<int> (c + 1));
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        for (int p = 1; p <= i; ++p)
          for (int q = 1; q <= j; ++q) {
            const int cur_sum = sum[i][j] - sum[p - 1][j] - sum[i][q - 1] + sum[p - 1][q - 1];
            if (cur_sum <= k) res = max(res, cur_sum);
          }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
