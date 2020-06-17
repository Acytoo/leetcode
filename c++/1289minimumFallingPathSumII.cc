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

// DP
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // 168 ms, 14.2 mb
 public:
  int minFallingPathSum(vector<vector<int>>& arr) {
    const int n = arr.size();
    int *dp = new int [n];
    for (int i = 0; i < n; ++i) dp[i] = arr[0][i];
    for (int i = 1; i < n; ++i) {
      int *tmp = new int [n];
      for (int j = 0; j < n; ++j) {
        int cur_sum = INT_MAX;
        for (int k = 0; k < n; ++k) {
          if (k == j) continue;
          cur_sum = min(cur_sum, dp[k]);
        }
        tmp[j] = arr[i][j] + cur_sum;
      }
      swap(dp, tmp);
      delete[] tmp;
    }
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) res = min(res, dp[i]);
    delete[] dp;
    return res;
  }
};

class Solution2 {  // 276 ms, 14.4 mb
 public:
  int minFallingPathSum(vector<vector<int>>& arr) {
    const int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (n));
    for (int i = 0; i < n; ++i) dp[0][i] = arr[0][i];
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int cur_sum = INT_MAX;
        for (int k = 0; k < n; ++k) {
          if (k == j) continue;
          cur_sum = min(cur_sum, dp[i - 1][k]);
        }
        dp[i][j] = arr[i][j] + cur_sum;
      }
    return *min_element(dp.back().begin(), dp.back().end());
  }
};

class Solution_1 {  // 684 ms, 14.2 mb
 public:
  int minFallingPathSum(vector<vector<int>>& arr) {
    const int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (n, INT_MAX));
    for (int i = 0; i < n; ++i) dp[0][i] = arr[0][i];
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k) {
          if (k == j) continue;
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][j]);
        }
    return *min_element(dp.back().begin(), dp.back().end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
