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
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int res = 0;
    for (int i = 1, stop = points.size(); i < stop; ++i) {
      const int dx = abs(points[i][0] - points[i - 1][0]),
                dy = abs(points[i][1] - points[i - 1][1]);
      res += min(dx, dy) + abs(dx - dy);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
