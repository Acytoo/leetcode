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
// From huahua
class Solution {
 public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    const int n = quiet.size();
    vector<int> res (n, -1);
    vector<vector<int>> g (n);
    for (const auto _: richer) g[_[1]].push_back(_[0]);
    function<void(int)>  dfs =
        [&] (const int i) {
          if (res[i] != -1) return ;
          res[i] = i;
          for (const int j: g[i]) {
            dfs(j);
            if (quiet[res[j]] < quiet[res[i]])
              res[i] = res[j];
          }
        };
    for (int i = 0; i < n; ++i) dfs(i);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
