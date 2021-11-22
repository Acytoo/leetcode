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
class Solution {  // vector, 20ms
  // topological sort with graph as adjacency list, dfs, acyclic
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (const auto &p : prerequisites)
      g[p[1]].push_back(p[0]);
    vector<Color> colors(numCourses, WHITE);
    function<bool(int)> dfs = [&] (const int x) {
      if (colors[x] == BLACK) return false;
      if (colors[x] == GRAY) return true;
      colors[x] = GRAY;
      for (const int nxt : g[x])
        if (dfs(nxt)) return true;
      colors[x] = BLACK;
      return false;
    };
    for (int i = 0; i < numCourses; ++i)
      if (dfs(i)) return false;
    return true;
  }
 private:
  enum Color {BLACK, GRAY, WHITE};
};


class Solution_DEQUE {  // deque 24 ms
  // topological sort with graph as adjacency list, dfs, acyclic
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<deque<int>> g(numCourses);
    for (const auto &p : prerequisites) g[p[1]].push_front(p[0]);
    vector<Color> colors (numCourses, WHITE);
    function<bool(int)> dfs = [&] (int x) {
      if (colors[x] == BLACK) return false;
      if (colors[x] == GRAY) return true;
      colors[x] = GRAY;
      while (!g[x].empty()) {
        if (dfs(g[x].front())) return true;
        g[x].pop_front();
      }
      colors[x] = BLACK;
      return false;
    };
    for (int i = 0; i < numCourses; ++i)
      if (dfs(i)) return false;
    return true;
  }
 private:
  enum Color {BLACK, GRAY, WHITE};
};

class Solution_SAME_DFS {
  // topological sort with graph as adjacency list
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<deque<int>> g(numCourses);
    for (const auto &p : prerequisites) g[p[1]].push_front(p[0]);
    vector<Color> colors (numCourses, WHITE);
    function<bool(int)> dfs = [&] (int x) {
      colors[x] = GRAY;
      while (!g[x].empty()) {
        int next = g[x].front();
        g[x].pop_front();
        if (colors[next] == BLACK) continue;
        if (colors[next] == GRAY) return false;  // cyclic
        if (!dfs(next)) return false;
      }
      colors[x] = BLACK;
      return true;
    };
    for (int i = 0; i < numCourses; ++i)
      if (colors[i] == WHITE && !dfs(i)) return false;
    return true;
  }
 private:
  enum Color {BLACK, GRAY, WHITE};
};


















// 拓扑次序(Topological Order)
class Solution_OLD {
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
