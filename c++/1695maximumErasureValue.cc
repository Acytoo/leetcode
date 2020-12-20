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

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// prefix_sum with array instead of unordered_set
class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int num_idx[10001];
    memset(num_idx, -1, sizeof num_idx);  // memset_set initialize member by char_size

    vector<int> prefix_sum {0};
    const int n = nums.size();
    prefix_sum.reserve(n + 1);

    int res = 0, pre = -1;
    for (int i = 0, stop = n; i < stop; ++i) {
      int &pre_idx_if_exist = num_idx[nums[i]];
      if (pre_idx_if_exist > -1 && pre_idx_if_exist >= pre) {
        res = max(res, prefix_sum[i] - prefix_sum[pre + 1]);
        pre = pre_idx_if_exist;
      }
      pre_idx_if_exist = i;
      prefix_sum.emplace_back(prefix_sum.back() + nums[i]);
    }
    return max(res, prefix_sum.back() - prefix_sum[pre + 1]);
  }
};

// two pointer
class Solution2 {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int num_occ[10001];
    memset(num_occ, 0, sizeof num_occ);
    int l = 0, r = 0, res = 0, sum = 0;
    for (int l = 0, r = 0, n = nums.size(); r < n; ) {
      const int cur = nums[r];
      ++num_occ[cur];
      sum += cur;
      ++r;
      while (num_occ[cur] > 1) {
        sum -= nums[l];
        --num_occ[nums[l]];
        ++l;
      }
      res = max(res, sum);
    }
    return res;
  }
};

// prefix sum
class Solution1 {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    const int n = nums.size();
    vector<int> prefix_sum {0};
    prefix_sum.reserve(n + 1);
    for (int i = 0; i < n; ++i)
      prefix_sum.emplace_back(prefix_sum.back() + nums[i]);
    unordered_map<int, int> num_idx;
    int res = 0, pre_ptr = -1, cur = 0;
    for (int i = 0; i < n; ++i) {
      if (num_idx.count(nums[i]) != 0 && num_idx[nums[i]] >= pre_ptr) { // same number and counted before

        cur = prefix_sum[i] - prefix_sum[pre_ptr + 1];
        res = max(res, cur);
        pre_ptr = num_idx[nums[i]];
      }
      num_idx[nums[i]] = i;
    }

    return max(res, prefix_sum.back() - prefix_sum[pre_ptr + 1]);
  }
};

int main() {
  Solution s;
  
  return 0;
}
