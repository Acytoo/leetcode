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

class Solution_TLE2 {
  // DP with memoization
 public:
  int splitArray(vector<int>& nums, int m) {
    vector<int> sums(1, 0);
    sums.reserve(nums.size());
    int sum = 0;
    for (int i = 0, n = nums.size(); i < n; ++i) sums.emplace_back(sum += nums[i]);
    function<int(int, int, int)> split = [&] (int l, int r, int k) {
      if (k == 1) return sums[r] - sums[l];
      int res = INT_MAX;
      for (int m = l + 1; m < r; ++m) {
        res = min(res, max(split(l, m, 1), split(m, r, k - 1)));
      }
      return res;
    };
    return split(0, nums.size(), m);
  }
};


class Solution_TLE {
  // DP
 public:
  int splitArray(vector<int>& nums, int m) {
    function<int(int, int, int)> split = [&] (int l, int r, int k) {
      if (k == 1) return accumulate(nums.begin() + l, nums.begin() + r, 0);
      int res = INT_MAX;
      for (int m = l + 1; m < r; ++m)
        res = min(res, max(split(l, m, 1), split(m, r, k - 1)));
      return res;
    };
    return split(0, nums.size(), m);
  }
};

int main() {
  Solution s;
  
  return 0;
}
