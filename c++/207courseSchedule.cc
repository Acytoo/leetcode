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
  bool canFinish(int num_courses, vector<vector<int>>& prerequisites) {
    graph_  = vector<vector<int>>(num_courses);  // init graph size
    for (const auto& pre: prerequisites)
      graph_[pre[1]].push_back(pre[0]);

    vector<STATUS_> status(num_courses, UNKNOWN);

    for (int i=0; i < num_courses; ++i)
      if (dfs(i, status)) return false;

    return true;
  }
 private:
  vector<vector<int>> graph_;  // topological order graph
  enum STATUS_{UNKNOWN, VISITED, VISITING};
  bool dfs(int cur, vector<STATUS_>& status) {
    if (status[cur] == VISITING) return true;
    if (status[cur] == VISITED) return false;
    // status UNKNOWN, start visiting
    status[cur] = VISITING;
    for (const int t: graph_[cur])
      if (dfs(t, status)) return true;

    status[cur] = VISITED;
    return false;
  }
};

int main() {
  Solution s;
  int a = 2;
  vector<vector<int>> pre = {{1,0}, {0, 1}};
  cout << s.canFinish(a, pre) << endl;
  return 0;
}
