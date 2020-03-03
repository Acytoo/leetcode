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
  bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
      int m = (l+r) >> 1;
      if (nums[m] == target)
        return true;
      if (nums[l] < nums[m]) {
        if (target < nums[m] && nums[l] <= target)
          r = m - 1;
        else
          l = m + 1;
      } else if (nums[m] < nums[l]){
        if (nums[m] < target && target <= nums[r])
          l = m + 1;
        else
          r = m - 1;
      } else {
        ++l;
      }
    }
    return false;
  }
};

class Solution1 {
 public:
  bool search(vector<int>& nums, int target) {
    for (int i: nums)
      if (i == target)
        return true;
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
