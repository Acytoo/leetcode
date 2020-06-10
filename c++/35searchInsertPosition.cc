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
class Solution {  // 12ms
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] < target)
        l = m + 1;
      else if (target < nums[m])
        r = m - 1;
      else return m;
    }
    return l;
  }
};

class Solution2 {  // 8ms
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (target > nums.back()) return nums.size();
    const int n = nums.size();
    int i = 0;
    while (i < n && target > nums[i]) ++i;
    return i;
  }
};

class Solution1 {  // 12ms
 public:
  int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};

int main() {
  Solution s;
  
  return 0;
}
