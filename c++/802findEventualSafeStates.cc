#include <iostream>
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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From HuaHua
class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<int> res;
    vector<State> states (n, UNKNOWN);
    function<State(int)> dfs =
        [&] (int cur) {
          if (states[cur] == VISITING) return UNSAFE;
          if (states[cur] != UNKNOWN) return states[cur];
          states[cur] = VISITING;
          for (int next: graph[cur])
            if (dfs(next) == UNSAFE)
              return states[cur] = UNSAFE;
          return states[cur] = SAFE;
        };
    for (int i=0; i<n; ++i)
      if (dfs(i) == SAFE)
        res.push_back(i);
    sort(res.begin(), res.end());
    return res;
  }
 private:
  enum State {UNKNOWN, VISITING, SAFE, UNSAFE};
};

int main() {
  Solution s;
  
  return 0;
}
