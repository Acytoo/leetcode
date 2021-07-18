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

// sort nums, four numbers: nums[i] < nums[j] < nums[k] < t
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    const int n = nums.size();
    if (n < 4) return {};
    sort(nums.begin(), nums.end());
    const int min_target = nums.front() * 4,
              max_target = nums.back() * 4;
    if (target < min_target || max_target < target) return {};
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) m[nums[i]] = i;
    set<vector<int>> s;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          const int left = target - nums[i] - nums[j] - nums[k];
          if (left < nums[k]) break;
          if (m.count(left) && m[left] > k) s.emplace(initializer_list<int>{nums[i], nums[j], nums[k], left});
        }
    vector<vector<int>> res;
    res.reserve(s.size());
    for (auto it = s.begin(); it != s.end(); )
      res.push_back(move(s.extract(it++).value()));  // c++ 17
    return res;
  }
};

class Solution_old {  // if the array contains duplicates
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    const int n = nums.size();
    if (n < 4) return {};
    sort(nums.begin(), nums.end());
    if ( (target > 0 && target > (nums.back() * 4)) ||
         (target < 0 && target < (nums.front() * 4)) ) return {};

    unordered_map<int, int> val_idx;  // if input array contains dups, the latter index override the former one
    for (int i = 0; i < n; ++i) val_idx[nums[i]] = i;
    set<vector<int>> res;  // same number appears more than one time
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          int t = target - nums[i] - nums[j] - nums[k];
          if (t < nums[k]) break;
          if (val_idx.count(t) && val_idx[t] > k) res.insert({nums[i], nums[j], nums[k], t}); // t.idx > k
        }
    return vector<vector<int>> (res.begin(), res.end());
  }
};

class Solution_WRONG {  // if the array contains duplicates
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    const int n = nums.size();
    if (n < 4) return {};
    sort(nums.begin(), nums.end());
    if ((target > 0 && target > (nums.back() * 4)) ||
        (target < 0 && target < (nums.front() * 4))) return {};

    unordered_map<int, int> val_idx;  // value-index
    for (int i = 0; i < n; ++i) val_idx[nums[i]] = i;
    set<vector<int>> res;  // same number appears more than one time
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          int t = target - nums[i] - nums[j] - nums[k];
          if (t < nums[k]) break;
          if (val_idx.count(t)) res.insert({nums[i], nums[j], nums[k], t});
        }
    return vector<vector<int>> (res.begin(), res.end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
