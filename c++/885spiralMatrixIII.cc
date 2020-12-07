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
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> res {{r0, c0}};
    const int res_size = R * C;
    if (res_size == res.size()) return res;

    // directions: R -> D -> L -> U, north-west is (0, 0)
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int steps = 1; // each direction go steps

    while (true) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < steps; ++j) {
          r0 += dirs[i][0];
          c0 += dirs[i][1];
          if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C)
            res.emplace_back(std::initializer_list<int>{r0, c0});
          if (res_size == res.size()) return res;
        }
      }
      ++steps;
      for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < steps; ++j) {
          r0 += dirs[i][0];
          c0 += dirs[i][1];
          if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C)
            res.emplace_back(std::initializer_list<int>{r0, c0});
          if (res_size == res.size()) return res;
        }
      }
      ++steps;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
