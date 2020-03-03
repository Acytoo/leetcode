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
    int l = 0, r = nums.size()-1;
    int res = -1;
    while (l <= r) {
      int m = (l+r) >> 1;
      if (nums[m] == target)
        return m;
      if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return res;
  }
};

class Solution1 {
 public:
  int search(vector<int>& nums, int target) {
    return search(nums, target, 0, nums.size()-1);
  }
 private:
  int search(vector<int>& nums, int target, int l, int r) {
    if (l >= r)
      return nums[l]==target? l: -1;
    int mid = (l+r) >> 1;
    if (nums[mid] == target)
      return mid;
    if (nums[mid] < target)
      return search(nums, target, mid+1, r);
    return search(nums, target, l, mid-1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
