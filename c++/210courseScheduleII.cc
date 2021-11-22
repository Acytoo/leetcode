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
class Solution {  // 16 ms
  // Topological sort
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (const auto &p : prerequisites)
      g[p[1]].push_back(p[0]);
    int time = 0;
    vector<Color> colors(numCourses);
    vector<int> res(numCourses);
    int idx = numCourses;
    function<bool(int)> dfs = [&] (const int x) {
      colors[x] = GRAY;
      ++time;
      for (const auto nxt : g[x]) {
        if (colors[nxt] == BLACK) continue;
        if (colors[nxt] == GRAY) return false;
        if (!dfs(nxt)) return false;
      }
      ++time;
      colors[x] = BLACK;
      res[--idx] = x;
      return true;
    };
    for (int i = 0; i < numCourses; ++i)
      if (colors[i] == WHITE && !dfs(i)) return {};
    return res;
  }
 private:
  enum Color {WHITE, GRAY, BLACK};
};


// 拓扑次序(Topological Order)
class Solution_OLD {
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
