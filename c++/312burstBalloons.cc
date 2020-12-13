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
class Solution {  // 40ms
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.emplace_back(1);

    vector<vector<int>> dp (n + 2, vector<int> (n + 2));
    for (int l = 1; l <= n; ++l)
      for (int i = 1, stopi = n - l + 1; i <= stopi; ++i) {
        int j = i + l - 1;
        for (int k = i; k <= j; ++k)
          dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1]  + dp[k + 1][j]);
      }
    return dp[1][n];
  }
};

class Solution1 {  // 20ms
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size(), dp_len = n + 2;
    nums.insert(nums.begin(), 1);  // return iterator
    nums.emplace_back(1);

    int dp[dp_len * dp_len];  // dp[n + 2][n + 2], 2d array
    memset(dp, 0, sizeof(dp));
    for (int l = 1; l <= n; ++l)
      for (int i = 1, stopi = n - l + 1; i <= stopi; ++i) {
        int j = i + l - 1;
        for (int k = i; k <= j; ++k)
          dp[i * dp_len + j] = max(dp[i * dp_len + j],
                                   dp[i * dp_len + k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[(k + 1) * dp_len + j]);
      }
    return dp[dp_len + n];
  }
};

int main() {
  Solution s;
  
  return 0;
}
