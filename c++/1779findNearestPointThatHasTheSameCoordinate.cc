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
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int res = -1, min_dis = INT_MAX;
    for (int i = 0, n = points.size(); i < n; ++i) {
      if (x == points[i][0]) {
        if (const int dis = abs(y - points[i][1]); dis < min_dis) {
          min_dis = dis;
          res = i;
        }
      } else if (y == points[i][1]) {
        if (const int dis = abs(x - points[i][0]); dis < min_dis) {
          min_dis = dis;
          res = i;
        }
      }
      if (min_dis == 0) return res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
