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
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int res = nums.back(), cur = res;
    for (int i = nums.size() - 1; i > 0; ) {
      if (nums[i] > nums[--i])
        cur += nums[i];
      else
        cur = nums[i];
      res = max(res, cur);
    }
    return res;
  }
};

class Solution2 {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int res = nums[0], cur = nums[0];
    for (int i = 1, n = nums.size(); i < n; ++i) {
      if (nums[i] > nums[i - 1])
        cur += nums[i];
      else
        cur = nums[i];
      res = max(res, cur);
    }
    return res;
  }
};

class Solution1 {
 public:
  int maxAscendingSum(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1, n = nums.size(); i < n; ++i) {
      if (nums[i] > nums[i - 1])
        dp[i] = nums[i] + dp[i - 1];
      else
        dp[i] = nums[i];
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
