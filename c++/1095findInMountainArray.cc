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

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();

// From huahua
class Solution {
 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    const int n = mountainArr.length();
    auto binary_search = [&](int l, int r, function<bool(int)> cond) {
      while (l < r) {
        const int m = (l + r) >> 1; // m = l + (r - l) / 2: if (l + r) > INT_MAX
        if (cond(m))
          r = m;
        else
          l = m + 1;
      }
      return l;
    };
    const int peak_index = binary_search(0, n - 1, [&](const int i) {
      return mountainArr.get(i) > mountainArr.get(i + 1);
    });

    const int l = binary_search(0, peak_index, [&](const int i) {
      return mountainArr.get(i) >= target;
    });

    if (mountainArr.get(l) == target) return l;

    const int r = binary_search(peak_index, n - 1, [&](const int i) {
      return mountainArr.get(i) <= target;
    });

    if (mountainArr.get(r) == target) return r;
    return -1;
  }
};

int main() {
  Solution s;

  return 0;
}
