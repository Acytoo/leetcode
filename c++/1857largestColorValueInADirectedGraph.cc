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

// n == colors.length
// m == edges.length
// 1 <= n <= 10^5
// 0 <= m <= 10^5
// colors consists of lowercase English letters.
// 0 <= aj, bj < n

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n = colors.size();
    vector<vector<int>> g(n);
    vector<int> indegree(n);
    for (const auto &e : edges) {
      g[e[0]].push_back(e[1]);
      ++indegree[e[1]];
    };

    deque<int> dq;
    for (int i = 0; i < n; ++i)
      if (indegree[i] == 0)
        dq.push_back(i);

    int res = 0, processed = 0;
    vector<vector<int>> cache(n, vector<int>(26));
    while (!dq.empty()) {
      const int cur = dq.front(); dq.pop_front();
      ++processed;
      res = max(res, ++cache[cur][colors[cur] - 'a']);
      for (const int nxt : g[cur]) {
        for (int i = 0; i < 26; ++i)
          cache[nxt][i] = max(cache[nxt][i], cache[cur][i]);
        if (--indegree[nxt] == 0)
          dq.push_back(nxt);
      }
    }
    return processed == n ? res : -1;
  }
};

class Solution_TLE3 {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n = colors.size();
    vector<vector<int>> g(n);
    for (const auto &e : edges) g[e[0]].push_back(e[1]);
    int res = 0;
    function<bool(int, unordered_set<int>, vector<int>)> dfs
        = [&] (const int x, unordered_set<int> s, vector<int> cur) {
          if (s.find(x) != s.end()) return false;
          s.insert(x);
          ++cur[colors[x] - 'a'];
          if (g[x].empty()) {
            int cm = 0;
            for (int i = 0; i < 26; ++i)
              cm = max(cm, cur[i]);
            res = max(res, cm);
          }
          for (const auto nxt : g[x])
            if (!dfs(nxt, s, cur)) return false;
          return true;
        };
    for (int i = 0; i < n; ++i) {
      unordered_set<int> s;
      vector<int> cur(26);
      if (!dfs(i, s, cur)) return -1;
    }
    return res;
  }
};

class Solution_TLE2 {  // O(V + E + VE)
  // DFS
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n = colors.size();
    vector<vector<int>> g(n);
    for (const auto &e : edges) g[e[0]].push_back(e[1]);
    vector<Color> status(n, WHITE);
    vector<int> seq;
    function<bool(int)> dfs = [&] (const int x) {
      if (status[x] == BLACK) return true;
      if (status[x] == GRAY) return false;
      status[x] = GRAY;
      for (const auto nxt : g[x]) {
        if (!dfs(nxt)) return false;
      }
      status[x] = BLACK;
      seq.push_back(x);
      return true;
    };

    int res = 1;
    function<void(int, vector<int>)> checkColor = [&] (int x, vector<int> cur) {
      ++cur[colors[x] - 'a'];
      if (g[x].empty()) {
        int cm = 0;
        for (int i = 0; i < 26; ++i)
          cm = max(cm, cur[i]);
        res = max(res, cm);
        return;
      }
      for (const auto nxt : g[x])
        checkColor(nxt, cur);
    };

    for (int i = 0; i < n; ++i)
      if (!dfs(i)) return -1;
    for (int i = n - 1; i >= 1; --i) {
      if (res > i) return res;
      vector<int> cur(26);
      checkColor(seq[i], cur);
    }
    return res;
  }
 private:
  enum Color {WHITE, GRAY, BLACK};
};


class Solution_TLE {
  // DFS
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n = colors.size();
    vector<vector<int>> g(n);
    for (const auto &e : edges) g[e[0]].push_back(e[1]);
    vector<Color> status(n, WHITE);
    vector<int> seq;
    function<bool(int)> dfs = [&] (const int x) {
      if (status[x] == BLACK) return true;
      if (status[x] == GRAY) return false;
      status[x] = GRAY;
      for (const auto nxt : g[x]) {
        if (!dfs(nxt)) return false;
      }
      status[x] = BLACK;
      seq.push_back(x);
      return true;
    };

    int res = 1;
    function<void(int, vector<int>)> checkColor = [&] (int x, vector<int> cur) {
      ++cur[colors[x]];
      if (g[x].empty()) {
        int cm = 0;
        for (int i = 'a'; i <= 'z'; ++i)
          cm = max(cm, cur[i]);
        res = max(res, cm);
        return;
      }
      for (const auto nxt : g[x])
        checkColor(nxt, cur);
    };

    for (int i = 0; i < n; ++i)
      if (!dfs(i)) return -1;
    for (int i = n - 1; i >= 0; --i) {
      vector<int> cur('z' + 1);
      checkColor(i, cur);
    }
    return res;
  }
 private:
  enum Color {WHITE, GRAY, BLACK};
};

int main() {
  Solution s;
  
  return 0;
}
