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
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> g (N + 1);
    for (const auto &d: dislikes) {
      g[d[0]].push_back(d[1]);
      g[d[1]].push_back(d[0]);
    }
    vector<int> colors (N + 1);
    function<bool(int, int)> dfs =
        [&] (int cur, int color) {
          colors[cur] = color;
          for (const auto &dis: g[cur]) {
            if (colors[dis] == color) return false;
            if (colors[dis] == 0 && !dfs(dis, -color)) return false;
          }
          return true;
        };

    for (int i = 1; i <= N; ++i)
      if (colors[i] == 0 && !dfs(i, 1))
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
