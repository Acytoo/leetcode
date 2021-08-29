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

// 1 must included, and 2 if n is not 1, unless 1 occered twice
// Greedy, 所以贪的是什么？
// 能不能用DP来解决，后一位是前一位加上1或者前两位加上2或者继续
// dp[i] = min(dp[i -1] + 1 (used before?),) 所以非常麻烦。
// 继续尝试Greedy，贪的是什么呢？
// 或者，能不能先看所有的数，能加成什么数，然后不能加成的数另算，那不能加成的数，要怎么计算呢？


// 继续抄……


static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From internet
class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int res = 0;
    const int nsize = nums.size();
    long miss = 1, i = 0;
    while (miss <= n) {
      if (i >= nsize || nums[i] > miss) {
        miss <<= 1;
        ++res;
      } else {
        miss += nums[i++];
      }
    }
    return res;
  }
};

class Solution1 {
 public:
  int minPatches(vector<int> &nums, int n ) {
    long miss = 1, i = 0;
    const int nsize = nums.size();
    while (miss <= n) {
      if (i >= nums.size() || nums[i] > miss) {
        nums.insert(nums.begin() + i, miss);
      }
      miss += nums[i++];
    }
    for (const int a : nums) cout << a << " ";
    return nums.size() - nsize;
  }
};

int main() {
  Solution s;
  
  return 0;
}
