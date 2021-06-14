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

// 1 <= ranges.length <= 50
// 1 <= starti <= endi <= 50
// 1 <= left <= right <= 50

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // From leetcode
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<bool> covered(51, false);
    for(const auto &range : ranges)
      for(int i = range[0]; i <= range[1]; i++)
        covered[i] = true;

    for(int i = left; i <= right; i++)
      if(!covered[i])
        return false;
    return true;
  }
};

class Solution2 {
  // From leetcode
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    sort(ranges.begin(), ranges.end());
    left = left - 1;
    for (auto &r : ranges) {
      if (r[0] > left + 1) return false;
      left = max(left, r[1]);
    }
    return left >= right;
  }
};

class Solution1 {
  // brute force
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    // sort(ranges.begin(), ranges.end());
    auto inRange = [&] (const int num, const int idx) {
      if (ranges[idx][0] <= num && num <= ranges[idx][1]) return true;
      return false;
    };
    const int n = ranges.size();
    for (int num = left; num <= right; ++num) {
      int i = 0;
      for ( ; i < n; ++i) {
        if (inRange(num, i)) break;
      }
      if (i == n) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
