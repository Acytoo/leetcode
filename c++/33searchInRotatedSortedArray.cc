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
#include <bitset>
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    function<int(int, int)> helper = [&] (int l, int r) {
      if (l > r) return -1;
      const int m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      if (nums[l] <= nums[m]) {
        if (nums[l] <= target && target < nums[m])
          return helper(l, m - 1);
        return helper(m + 1, r);
      } else {
        if (nums[m] < target && target <= nums[r])
          return helper(m + 1, r);
        return helper(l, m - 1);
      }
    };
    return helper(0, nums.size() - 1);
  }
};


class Solution_WA {  // wrong case [3, 1]
  // binary search
 public:
  int search(vector<int>& nums, int target) {
    function<int(int, int)> helper = [&] (int l, int r) {
      if (l > r) return -1;
      if (l <= r - 1) {
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
      }
      const int m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      if (nums[l] < nums[r]) {
        if (target < nums[m]) return helper(l, m - 1);
        return helper(m + 1, r);
      } else if (nums[l] < nums[m]) {
        if (target <= nums[l] && target < nums[m]) return helper(l, m - 1);
        return helper(m + 1, r);
      } else {  // nums[m] < nums[r]
        if (target > nums[m] && target <= nums[r]) return helper(m + 1, r);
        return helper(l, m - 1);
      }
    };
    return helper(0, nums.size() - 1);
  }
};

class Solution_OLD {
 public:
  int  search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      const int m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      if (nums[l] <= nums[m]) {
        if (nums[l] <= target && target < nums[m])
          r = m - 1;
        else
          l = m + 1;
      } else {
        if (nums[m] < target && target <= nums[r])
          l = m + 1;
        else
          r = m - 1;
      }
    }
    return -1;
  }
};


int main() {
  Solution s;
  
  return 0;
}
