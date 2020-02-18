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
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] == target) {
        int start = m, end = m;
        if (nums[l] == target) {
          start = l;
        } else {
          while (l<=start && nums[start]==target)  //
            --start;
          ++start;
        }
        if (nums[r] == target) {
          end = r;
        } else {
          while (end<=r && nums[end]==target)
            ++end;
          --end;
        }
        return {start, end};
      }
      if (nums[m] < target)
        l = m + 1;
      else  // target < mid
        r = m - 1;
    }
    return {-1, -1};
  }
};

int main() {
  Solution s;
  
  return 0;
}
