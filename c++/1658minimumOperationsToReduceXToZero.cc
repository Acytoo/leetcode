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
  // Sliding window
 public:
  int minOperations(vector<int>& nums, int x) {
    const int target = accumulate(nums.begin(), nums.end(), 0) - x; // sliding window sum target
    int res = INT_MAX;
    for (int l = 0, r = 0, cur = 0, n = nums.size(); r < n; ++r) {
      cur += nums[r];
      while (cur > target && l <= r) cur -= nums[l++];
      if (cur == target) res = min(res, n - (r - l + 1));
    }
    return res == INT_MAX? -1: res;
  }
};

class Solution_TLE {
  // DFS with trim
 public:
  int minOperations(vector<int>& nums, int x) {
    int res = INT_MAX;
    function<void(int, int, int, int)> dfs = [&] (const int l, const int r, const int cur, const int x) {
      if (x == 0) {
        res = cur;
        return;
      }
      if (x < 0 || l > r || cur > res) return;
      dfs(l + 1, r, cur + 1, x - nums[l]);
      dfs(l, r - 1, cur + 1, x - nums[r]);
    };
    dfs(0, nums.size() - 1, 0, x);
    return res == INT_MAX? -1: res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
