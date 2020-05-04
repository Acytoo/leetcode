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

using namespace std;

// nums: positive nums
// product less than k, no positive num less than 1
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Sliding window
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;

    int product = nums[0], l = 0, r = 0, res = product < k ;
    const int n = nums.size();

    while (++r < n) {
      product *= nums[r];
      while (k <= product) product /= nums[l++];
      res += r - l + 1;
    }
    return res;
  }
};

class Solution_same_k {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 0) return 0;

    int product = nums[0], l = 0, r = 0, res = product < k ;
    const int n = nums.size();

    while (++r < n) {
      product *= nums[r];
      while (l <= r && k <= product) product /= nums[l++];
      res += r - l + 1;
    }
    return res;
  }
};

class Solution_TLE {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res = 0;
    const int n = nums.size();
    for (int i=0; i<n; ++i) {
      if (k <= nums[i]) continue;
      ++res;
      int product = nums[i];
      for (int j=i+1; j<n; ++j) {
        product *= nums[j];
        if (k <= product) break;
        ++res;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {10, 5, 2, 6};
  a = {1,2,3};
  cout << s.numSubarrayProductLessThanK(a, 1) << endl;
  return 0;
}
