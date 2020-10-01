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

// prefix sum, from huahua
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    const int n = nums.size();
    vector<int> dp (n + 1);
    unordered_map<int, int> sum_idx;
    sum_idx[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      const int t = sum - target;
      dp[i + 1] = dp[i];
      if (sum_idx.count(t))
        dp[i + 1] = max(dp[i], dp[sum_idx[t] + 1] + 1);
      sum_idx[sum] = i;
    }
    return dp[n];
  }
};

int main() {
  Solution s;
  
  return 0;
}
