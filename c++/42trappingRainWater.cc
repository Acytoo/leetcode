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
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int res = 0;
    int l = 0, r = height.size() - 1;
    int max_l = height.front(), max_r = height.back();
    while (l < r) {
      if (max_l < max_r) {
        res += max_l - height[l];
        max_l = max(max_l, height[++l]);
      } else {
        res += max_r - height[r];
        max_r = max(max_r, height[--r]);
      }
    }
    return res;
  }
};

class Solution_o_n {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int res = 0;
    const int n = height.size();
    vector<int> l (n), r (n);
    l[0] = height[0];
    r.back() = height.back();
    for (int i = 1; i < n; ++i) l[i] = max(l[i - 1], height[i]);
    for (int i = n - 2; i >= 0; --i) r[i] = max(r[i + 1], height[i]);
    for (int i = 0; i < n; ++i) res += min(l[i], r[i]) - height[i];
    return res;
  }
};

class Solution_o_n^2 {
 public:
  int trap(vector<int>& height) {
    int res = 0;
    auto kb = height.cbegin(), ke = height.cend(); // const auto
    for (int i = 0, n = height.size(); i < n; ++i) {
      int l = *max_element(kb, kb + i + 1),
          r = *max_element(kb + i, ke);
      res += min(l, r) - height[i];
    }
    return res;
  }
};

class Solution_TLE {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int lowest = height[0], highest = height[0];
    for (const int h : height)
      if (h < lowest)
        lowest = h;
      else if (h > highest)
        highest = h;

    int cur = 0, res = 0, n = height.size();
    for (int level = lowest; level <= highest; ++level) {
      int i = 0;
      cur = 0;
      while (i < n && height[i] <= level) ++i;
      while (++i < n) {
        if (level < height[i]) {
          res += cur;
          cur = 0;
        } else {
          ++cur;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
