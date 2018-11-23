#include <iostream>
#include <vector>

using namespace std;
/* Idea from https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity, thanks to mzchen*/
static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();

// class Solution1 {
// public:
//   int maxProduct(vector<int>& nums) {
//     int r = nums[0], n = nums.size(), imax = r, imin = r;

//     for (int i = 1; i < n; i++) {
//       if (nums[i] < 0)
// 	swap(imax, imin);

//       imax = max(nums[i], imax * nums[i]);
//       imin = min(nums[i], imin * nums[i]);
//       r = max(r, imax);
//     }
//     return r;
//   }
// };

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int res = nums[0], n = nums.size(), tempMax = res, tempMin = res;
    for (int i=1; i < n; i++) {
      if (nums[i] < 0)
	swap(tempMax, tempMin);
      tempMax = max(nums[i] * tempMax, nums[i]);
      tempMin = min(nums[i] * tempMin, nums[i]);
      res = max(res, tempMax);
    }
    return res;
  }
 };


int main () {
  Solution1 s;
  vector <int> a = {2, 3, -2, 4};
  cout << s.maxProduct(a) << endl;
  return 0;
}
