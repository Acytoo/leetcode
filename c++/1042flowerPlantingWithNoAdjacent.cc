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

// It is guaranteed an answer exists.
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> g (N);
    for (const auto &path: paths) {
      g[path[0] - 1].emplace_back(path[1] - 1);
      g[path[1] - 1].emplace_back(path[0] - 1);
    }
    vector<int> res (N);
    for (int i = 0; i < N; ++i) {
      int mask = 0;
      for (const int adja: g[i])
        mask |= (1 << res[adja]);
      for (int color = 1; color <= 4; ++color)
        if ((mask & (1 << color)) == 0)
          res[i] =  color;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
