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
// From huahua
class Solution {  // linear time and sapce
 public:
  int maximumGap(vector<int>& nums) {
    const int n = nums.size();
    if (n < 2) return 0;

    const auto mm = minmax_element(nums.begin(), nums.end());
    const int range = *mm.second - *mm.first,
           bin_size = range / n + 1;
    vector<int> min_vals(n, INT_MAX), max_vals(n, INT_MIN);
    for (const int num : nums) {
      const int index = (num - *mm.first) / bin_size;
      min_vals[index] = min(min_vals[index], num);
      max_vals[index] = max(max_vals[index], num);
    }

    int res = 0, prev_max = max_vals[0];
    for (int i = 1; i < n; ++i) {
      if (min_vals[i] != INT_MAX) {
        res = max(res, min_vals[i] - prev_max);
        prev_max = max_vals[i];
      }
    }
    return res;
  }
};

class Solution1 {  // nlogn time
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = nums.size() - 1; i >= 1; ) {
      const int tmp = nums[i] - nums[--i];
      if (res < tmp) res = tmp;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
