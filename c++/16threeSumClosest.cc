#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// many solutions
// sort first

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[2];
    for (auto p1 = nums.begin(), stop = nums.end() - 2; p1 != stop; ++p1) {
      auto p2 = p1 + 1, p3 = nums.end() - 1;
      while (p2 != p3) {
        int tempRes = *p1 + *p2 + *p3;
        if (tempRes == target)
          return tempRes;
        if (abs(target - tempRes) < abs(target - res))
          res = tempRes;
        if (tempRes > target)
          --p3;
        else
          ++p2;
      }
    }
    return res;
  }

  // from leetcode the fastest one
  int threeSumClosest1(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0, min_diff = INT_MAX;
    for (int i = 0, stop = nums.size() - 2; i < stop; i++) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      for(int l = i + 1, r = nums.size() - 1; l < r; ) {
        int sum = nums[l] + nums[r] + nums[i];
        int diff = abs(sum - target);
        if (diff == 0) return sum;
        if (diff < min_diff) {
          res = sum;
          min_diff = diff;
        }
        sum < target? l ++ : r--;
      }
    }
    return res;
  }

};

int main() {
  Solution s;
  vector<int> a = {-1, 2, 1, -4};
  cout << *a.end() << endl;// << endl;
  cout << s.threeSumClosest(a, 1) << endl;
  return 0;
}
