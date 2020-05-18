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
  int minAreaRect(vector<vector<int>>& points) {
    const int n = points.size();
    if (n < 4) return 0;
    unordered_map<int, unordered_set<int>> m;
    for (const auto &point: points) m[point[0]].insert(point[1]);
    int res = INT_MAX;

    for (int i = n - 1; i >= 1; --i)
      for (int j = i - 1; j >= 0; --j) {
        int x1 = points[i][0],
            y1 = points[i][1],
            x2 = points[j][0],
            y2 = points[j][1];
        if (x1 == x2 || y1 == y2) continue;
        if (m[x1].count(y2) == 0 || m[x2].count(y1) == 0) continue;
        res = min(res, abs(x1 - x2) * abs(y1 - y2));
      }
    return res == INT_MAX? 0: res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
