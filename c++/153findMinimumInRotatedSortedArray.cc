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

// 0 1 2 4 5 6 7
// 4 5 6 7 0 1 2
// 1 2 4 5 6 7 0

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// O (log n)
class Solution {
 public:
  int findMin(vector<int>& nums) {
    function<int(int, int)> helper = [&] (const int l, const int r) {
      if (l + 1 >= r) return min(nums[l], nums[r]);
      if (nums[l] < nums[r]) return nums[l];
      const int m = l + ((r - l) >> 1);
      return min(helper(l, m - 1), helper(m, r));
    };
    return helper(0, nums.size() - 1);
  }
};


// return *min_element();

class Solution_____________ {  // O (n) and passed
 public:
  int findMin(vector<int>& nums) {
    int res = nums.front();
    for (const int a : nums)
      if (a < res) return a;
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
