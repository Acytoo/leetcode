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
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int res = 0, x = 0, y = 0, d = 0;
    constexpr int dirs[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    unordered_map<int, unordered_set<int>> obst;
    for (const auto &o: obstacles) obst[o[0]].insert(o[1]);
    for (int c: commands) {
      if (c == -2) {
        d = ++d <= 3? d: d - 4;
      } else if (c == -1) {
        d = --d >= 0? d: d + 4;
      } else {
        while (c--) {
          int xx = x + dirs[d][0], yy = y + dirs[d][1];
          if (obst.count(xx) && obst[xx].count(yy)) break;
          x = xx; y = yy;
          res = max(res, x * x + y * y);
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
