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

// floyd-warshall
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> g (n, vector<int> (n));
    for (const auto &pre: prerequisites) g[pre[0]][pre[1]] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          g[j][k] |= g[j][i] & g[i][k];
    vector<bool> res;
    res.reserve(queries.size());
    for (const auto &q: queries) res.emplace_back(g[q[0]][q[1]]);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
