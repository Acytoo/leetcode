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

// 能够进一个子集的一定是等比数列中的某几项，所以可以将所有的数都放进set，
// 然后从1开始每次乘上一个数，做为公比，看看哪些数可以在一个子集中。
// 但是这种方法时间复杂度太大。

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    const int n = nums.size();
    vector<int> lens(n);
    int cur_len = 0, last = 0;
    vector<int> parent(n);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0) {
          if (lens[i] < lens[j] + 1) {
            lens[i] = lens[j] + 1;
            parent[i] = j;
          }
        }
      }
      if (lens[i] > cur_len) {
        cur_len = lens[i];
        last = i;
      }
    }
    vector<int> res;
    res.reserve(cur_len);
    for (int i = 0; i <= cur_len; ++i) {
      res.emplace_back(nums[last]);
      last = parent[last];
    }
    return res;
  }
};

class Solution_OLD {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.empty()) return {};
    sort(nums.rbegin(), nums.rend());
    const int n = nums.size();
    vector<int> dp (n), parent (n), res;
    iota(parent.begin(), parent.end(), 0);
    int cur_max = 0, idx = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        if (nums[j] % nums[i] != 0) continue;
        if (dp[i] < dp[j] + 1) {dp[i] = dp[j] + 1; parent[i] = j;}
        if (cur_max < dp[i]) {cur_max = dp[i]; idx = i;}
      }
    res.reserve(cur_max);
    while (parent[idx] != idx) {
      res.emplace_back(nums[idx]);
      idx = parent[idx];
    }
    res.emplace_back(nums[idx]);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
