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
// All positive number must be counted
// From huahua
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> cache(n);
    deque<int> dq{0};
    cache[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      cache[i] = nums[i] + cache[dq.front()];
      while (!dq.empty() && cache[i] >= cache[dq.back()]) dq.pop_back();
      while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
      dq.push_back(i);
    }
    return cache[n - 1];
  }
};


class Solution_TLE2 {
  // DP
 public:
  int maxResult(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> cache (n, INT_MIN);
    cache[0] = nums[0];
    function<void(int)> dp = [&](const int idx) {
      int pre_max = cache[idx - 1];
      for (int i = max(0, idx - k); i < idx; ++i)
        pre_max = max(pre_max, cache[i]);
      cache[idx] = pre_max + nums[idx];
    };
    for (int i = 1; i < n; ++i)
      dp(i);
    return cache.back();
  }
};

class Solution_TLE1 {
  // DFS
 public:
  int maxResult(vector<int>& nums, int k) {
    const int n = nums.size(), last_idx = n - 1;
    vector<int> cache (n, INT_MIN);
    cache[0] = nums[0];
    function<void(int)> dfs = [&](const int idx) {
      if (idx >= n) return;
      for (int i = idx + 1, stop = min(last_idx, idx + k); i <= stop; ++i) {
        cache[i] = max(cache[i], cache[idx] + nums[i]);
        dfs(i);
      }
    };
    dfs(0);
    return cache.back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
