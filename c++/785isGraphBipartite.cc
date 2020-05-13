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
  bool isBipartite(vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<int> colors (n);
    function<bool(int, int)> dfs =
        [&] (int cur, int color) {
          if (colors[cur]) return colors[cur] == color;
          colors[cur] = color;
          for (const int next: graph[cur])
            if (!dfs(next, -color))
              return false;
          return true;
        };
    for (int i = 0; i < n; ++i)
      if (colors[i] == 0 && !dfs(i, 1))
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
