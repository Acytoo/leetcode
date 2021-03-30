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
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    });
    vector<int> dp;
    for (int i = 0, n = envelopes.size(); i < n; ++i) {
      auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
      if (it == dp.end())
        dp.emplace_back(envelopes[i][1]);
      else
        *it = envelopes[i][1];
    }
    return dp.size();
  }
};

class Solution_slow {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int res = 0;
    vector<int> dp (envelopes.size());
    for (int i = 0, n = envelopes.size(); i < n; ++i) {
      dp[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

class Solution_slow_RSort {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.rbegin(), envelopes.rend());
    int res = 0;
    vector<int> dp (envelopes.size());
    for (int i = 0, n = envelopes.size(); i < n; ++i) {
      dp[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (envelopes[j][1] > envelopes[i][1] && envelopes[j][0] > envelopes[i][0])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

class Solution_FROM_leetcode {
 public:
  // Longest Increasing Subsequence, O(nlgn)
  int maxEnvelopes(vector<vector<int>>& es) {
    sort(es.begin(), es.end(), [](const vector<int>& a, const vector<int>& b) {
      return (a[0] == b[0]) ? a[1] >= b[1] : a[0] < b[0];
    });

    vector<int> dp;   // dp[i]: the last value of the sequence with length i.
    int maxd = 1;
    for (int i = 0; i < es.size(); i++) {
      auto it = lower_bound(dp.begin(), dp.end(), es[i][1]);
      if (it == dp.end())
        dp.push_back(es[i][1]);
      else
        //dp[it-dp.begin()] = es[i][1];
        *it = es[i][1];
    }
    return dp.size();
  }

  // Longest Increasing Subsequence, O(n^2)
  int maxEnvelopes_dp_n2(vector<vector<int>>& envelopes) {
    vector<pair<int, int>> ev;
    for (auto& e : envelopes) {
      ev.push_back({e[0], e[1]});
    }
    sort(ev.begin(), ev.end());

    vector<int> dp(ev.size(), 1);
    int maxd = 1;
    for (int i = 1; i < ev.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (ev[j].first < ev[i].first && ev[j].second < ev[i].second) {
          dp[i] = max(dp[i], dp[j] + 1);
          maxd = max(maxd, dp[i]);
        }
      }
    }
    return maxd;
  }

  // Using DGA topo sort, but timeout!
  int maxEnvelopes__DAG_toposort_timeout(vector<vector<int>>& envelopes) {
    vector<vector<int>> adj(envelopes.size(), vector<int>()); // adj matrix: i -> vector of adj nodes.
    // Build graph in adj matrix.
    for (int i = 0; i < envelopes.size(); i++) {
      for (int j = i+1; j < envelopes.size(); j++) {
        if (envelopes[i][0] < envelopes[j][0] &&
            envelopes[i][1] < envelopes[j][1])
          adj[i].push_back(j);
        if (envelopes[j][0] < envelopes[i][0] &&
            envelopes[j][1] < envelopes[i][1])
          adj[j].push_back(i);
      }
    }
#if 0
    for (int i = 0;i < adj.size(); i++) {
      printf("adj of %d: ", i);
      for (int j: adj[i])
        printf("%d ", j);
      printf("\n");
    }
#endif

    // Topo sort: dfs visiting order is the reverse of topo sort order.
    vector<int> stack;
    vector<int> mark(adj.size(), -1);
    for (int i = 0; i < adj.size(); i++) {
      dfs(adj, i, mark, stack);
    }

    printf("topo sort result: ");
    for (int i = stack.size()-1; i >= 0; i--) {
      printf("%d ", stack[i]);
    }
    printf("\n");

    vector<int> dist(adj.size(), 1);
    int maxd = 1;
    for (int i = stack.size()-1; i >= 0; i--) {
      for (int j = 0; j < adj[stack[i]].size(); j++) {
        int a = stack[i];
        int b = adj[a][j];
        if (dist[a] + 1 > dist[b]) {
          dist[b] = dist[a] + 1;
          maxd = max(maxd, dist[b]);
        }
        //printf("node %d, updating %d, to dist=%d\n", a, b, dist[b]);
      }
    }
#if 0
    for (int d : dist) {
      printf("%d ", d);
    }
    printf("\n");
#endif
    return maxd;
  }

  void dfs(const vector<vector<int>>& adj, int root, vector<int>& mark, vector<int>& stack) {
    if (mark[root] != -1)
      return;
    mark[root] = 0;
    for (int j = 0; j < adj[root].size(); j++) {
      dfs(adj, adj[root][j], mark, stack);
    }
    stack.push_back(root);
    mark[root] = 1;
  }
};

class Solution_WA {  // Note: You cannot rotate an envelope. ==> You CAN rotate an envelope
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    for (auto &e : envelopes)
      if (e[0] < e[1])
        swap(e[1], e[0]);
    sort(envelopes.rbegin(), envelopes.rend());
    int res = 0;
    vector<int> dp (envelopes.size());
    for (int i = 0, n = envelopes.size(); i < n; ++i) {
      dp[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (envelopes[j][1] > envelopes[i][1] && envelopes[j][0] > envelopes[i][0])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
