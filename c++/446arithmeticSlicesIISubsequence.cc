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
  int numberOfArithmeticSlices(vector<int>& nums) {
    const int n = nums.size();
    vector<unordered_map<int, int>> dp(n);
    int res = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        long delta = static_cast<long>(nums[i]) - nums[j];
        if (delta > INT_MAX || delta < INT_MIN) continue;
        int diff = static_cast<int>(delta);
        ++dp[i][diff];
        if (dp[j].count(diff)) {
          res += dp[j][diff];
          dp[i][diff] += dp[j][diff];
        }
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
