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
// DFS
class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    const int kTarget = graph.size() - 1;
    vector<vector<int>> res;
    vector<int> path {0};  // 0: start node
    function<void(void)> dfs =
        [&] () {
          if (path.back() == kTarget) {
            res.push_back(path);
            return ;
          }
          for (int next: graph[path.back()]) {
            path.push_back(next);
            dfs();
            path.pop_back();
          }
        };
    dfs();
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
