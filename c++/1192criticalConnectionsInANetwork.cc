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
// Trojan from huahua
class Solution {
 public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> g(n), res;
    vector<int> ts(n, INT_MAX);
    int t = 0;

    function<int(int, int)> tarjan = [&] (int i, int p) {
      int min_i = ts[i] = ++t;
      for (int j : g[i]) {
        if (ts[j] == INT_MAX) {
          int min_j = tarjan(j, i);
          min_i = min(min_i, min_j);
          if (ts[i] < min_j)
            res.emplace_back(initializer_list<int>{i, j});
        } else if (j != p) {
          min_i = min(min_i, ts[j]);
        }
      }
      return min_i;
    };

    for (const auto &e : connections) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    tarjan(0, -1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
