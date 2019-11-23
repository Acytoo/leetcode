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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Rewrite house robber in c++
// dp with o(1) space, dp2: top 2, dp1: top 1
class Solution1 {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;
    int dp1=0, dp2=0;
    for (int i=0; i<n; ++i) {
      int dp = max(dp2+nums[i], dp1);
      dp2 = dp1;
      dp1 = dp;
    }
    return dp1;
  }
};
// using recursion and memorization
// This is 4ms faster than solution 2...
class Solution {
public:
  int rob(vector<int>& nums) {
    const int n = nums.size();
    if (!n) return 0;
    mem_ = vector<int>(n, -1);
    return rob(nums, n-1);
  }
private:
  int rob(const vector<int>& nums, int n) {
    if (n < 0) return 0;
    if (mem_[n] >= 0) return mem_[n];
    return mem_[n] = max(rob(nums, n-2)+nums[n], rob(nums, n-1));
  }
  vector<int> mem_;
};



// using recursion and memorization
class Solution2 {
public:
  int rob(vector<int>& nums) {
    const int n = nums.size();
    if (!n) return 0;
    nums_ = nums;
    mem_ = vector<int>(n, -1);
    return rob(n-1);
  }
private:
  int rob(int n) {
    if (n < 0) return 0;
    if (mem_[n] >= 0) return mem_[n];
    return mem_[n] = max(rob(n-2)+nums_[n], rob(n-1));
  }
  vector<int> nums_;
  vector<int> mem_;
};

int main() {
  Solution s;
  vector<int> a = {1,3,5,6,8};
  cout << s.rob(a) << endl;
  return 0;
}
