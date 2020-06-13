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
