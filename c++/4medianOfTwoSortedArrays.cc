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
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size(), n2 = nums2.size();
    if (n2 < n1) return findMedianSortedArrays(nums2, nums1);
    const int k = (n1 + n2 + 1) >> 1;
    int l = 0, r = n1;
    while (l < r) {
      const int m1 = (l + r) >> 1, m2 = k - m1;
      if (nums1[m1] < nums2[m2 - 1])
        l = m1 + 1;
      else
        r = m1;
    }
    const int m1 = l, m2 = k - l, c1 = max(m1 == 0? INT_MIN: nums1[m1 - 1],
                                           m2 == 0? INT_MIN: nums2[m2 - 1]);
    if ((n1 + n2) & 1) return static_cast<double>(c1);
    const int c2 = min(m1 == n1? INT_MAX: nums1[m1],
                       m2 == n2? INT_MAX: nums2[m2]);
    return (c1 + c2) / 2.0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
