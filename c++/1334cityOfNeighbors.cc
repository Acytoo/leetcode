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
#include <set>
#include <functional>
#include <bitset>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Dijkstra
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int, int>>> g(n);
    for (const vector<int>& e: edges) {
      g[e[0]].emplace_back(e[1], e[2]);
      g[e[1]].emplace_back(e[0], e[2]);
    }

    function<int(int)> dijkstra = [&](int s) {
                                    vector<int> dist(n, INT_MAX / 2);
                                    set<pair<int, int>> q;
                                    vector<set<pair<int, int>>::const_iterator> its(n);
                                    dist[s] = 0;
                                    for (int i=0; i<n; ++i)
                                      its[i] = q.emplace(dist[i], i).first;
                                    while (!q.empty()) {
                                      auto it = q.begin();
                                      int d = it->first;
                                      int u = it->second;
                                      q.erase(it);
                                      if (distanceThreshold < d)
                                        break;
                                      for (const auto& p: g[u]) {
                                        int v = p.first;
                                        int w = p.second;
                                        if (dist[v] <=d+w)
                                          continue;
                                        q.erase(its[v]);
                                        its[v] = q.emplace(dist[v] = d+w, v).first;
                                      }
                                    }
                                    return count_if(dist.begin(), dist.end(), [distanceThreshold](int d){return d<=distanceThreshold;});
                                  };
    int res = -1;
    int min_neighbor = INT_MAX;
    for (int i=0; i<n; ++i) {
      int neighbor = dijkstra(i);
      if (neighbor <= min_neighbor) {
        min_neighbor = neighbor;
        res = i;
      }
    }
    return res;
  }
};

// Floyd-Warshell, TLE
class Solution1{
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
    for (auto& e: edges)
      dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];
    for (int k=0; k<n; ++k)
      for (int u=0; u<n; ++u)
        for (int v=0; v<n; ++v)
          dp[u][v] = min(dp[u][v], dp[u][k]+dp[k][v]);
    int res = -1;
    int min_neighbor = INT_MIN;
    for (int u=0; u<n; ++u) {
      int neighbor = 0;
      for (int v=0; v<n; +v)
        if (v!=n && dp[u][v]<=distanceThreshold)
          ++neighbor;
      if (min_neighbor < neighbor) {
        min_neighbor = neighbor;
        res = u;
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
