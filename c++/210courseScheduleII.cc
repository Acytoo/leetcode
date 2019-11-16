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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 拓扑次序(Topological Order)
class Solution {
 public:
  vector<int> findOrder(int num_courses, vector<vector<int>>& prerequisites) {
    graph_  = vector<vector<int>>(num_courses);  // init graph size
    for (const auto& pre: prerequisites)
      graph_[pre[1]].push_back(pre[0]);

    vector<STATUS_> status(num_courses, UNKNOWN);
    vector<int> res;

    for (int i=0; i < num_courses; ++i)
      if (dfs(i, status, res)) return {};
    reverse(res.begin(), res.end());
    return res;
  }

 private:
  vector<vector<int>> graph_;  // topological order graph
  enum STATUS_{UNKNOWN, VISITED, VISITING};

  bool dfs(int cur, vector<STATUS_>& status, vector<int>& res) {
    if (status[cur] == VISITING) return true;  // Cycle
    if (status[cur] == VISITED) return false;  // Already visited
    // status UNKNOWN, start visiting
    status[cur] = VISITING;
    for (const int t: graph_[cur])
      if (dfs(t, status, res)) return true;

    status[cur] = VISITED;
    res.push_back(cur);
    return false;
  }
};

int main() {
  Solution s;
  int a = 2;
  vector<vector<int>> pre = {{1,0}};
  vector<int> res = s.findOrder(a, pre);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
