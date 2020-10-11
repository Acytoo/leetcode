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
class Solution {  // 1D array
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<int> cites (n), g (n * n);
    for_each(roads.begin(), roads.end(), [&] (const auto &r) {
      ++cites[r[0]]; ++cites[r[1]];
      g[r[0] * n + r[1]] = g[r[1] * n + r[0]] = 1;
    });
    int res = 0, cur = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cur = cites[i] + cites[j] - g[i * n + j];
        res = max(res, cur);
      }
    return res;
  }
};

class Solution1 {  // 2D array
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<int>> g (n, vector<int> (n));
    vector<int> cites (n);
    for_each(roads.begin(), roads.end(), [&] (const auto &r) {
      ++cites[r[0]]; ++cites[r[1]];
      g[r[0]][r[1]] = 1; g[r[1]][r[0]] = 1;
    });
    int res = 0, cur = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cur = cites[i] + cites[j] - g[i][j];
        res = max(res, cur);
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
