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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

// Permutations, not combinations
// DP
// Top-down is faster than botton-up
// bottom-up
class Solution1 {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<long> dp(target+1);
    dp[0] = 1;
    // sort nums first
    sort(nums.begin(), nums.end());
    for (int i=1; i<=target; ++i) {
      for (auto num: nums) {
        if (i < num) break;
        dp[i] += dp[i-num];
      }
    }
    return dp[target];
  }
};
// Top-down DP
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    unordered_map<int, int> mem;
    return dfs(nums, target, mem);
  }
  int dfs(vector<int>& nums, int target, unordered_map<int, int>& mem) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    auto it = mem.find(target);
    if (it != mem.end()) return it->second;

    int res = 0;
    for (int num: nums)
      res += dfs(nums, target-num, mem);
    return mem[target] = res;   // update mem
  }
};

int main() {
  Solution s;
  vector<int> a = {1, 2, 3};
  cout << s.combinationSum4(a, 4) << endl;
  return 0;
}
