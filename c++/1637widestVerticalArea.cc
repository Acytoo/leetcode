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
class Solution {  // O(n) space
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    const int n = points.size();
    vector<int> ps;
    ps.reserve(n);
    // for (int i = 0, n = points.size(); i < n; ++i) ps[i] = points[i][0]; // n in for loop: local variable, faster
    // for (int i = n - 1; i >= 0; --i) ps[i] = points[i][0];
    for (const auto &a: points) ps.emplace_back(a[0]);
    sort(ps.begin(), ps.end());

    int res = 0;
    for (int i = n - 1; i > 0; )
      res = max(res, ps[i] - ps[--i]);
    return res;
  }
};

class Solution1 {  // O(1) space
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [&] (const vector<int> &a, const vector<int> &b) {
      return a[0] > b[0];  // Just sort() without lambda also works, but this way's faster
    });
    int res = 0;
    for (int i = 0, n = points.size() - 1; i < n; ++i) {
      res = max(res, points[i][0] - points[i + 1][0]);
    }
    return res;
  }
};
int main() {
  Solution s;
  
  return 0;
}
