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
class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<int> parents(n, 0);
    vector<int> sizes(n, 1);

    for (const auto& edge: edges) {
      int u = edge[0];
      int v = edge[1];
      if (!parents[u]) parents[u] = u;
      if (!parents[v]) parents[v] = v;
      int pu = findParent(u, parents);
      int pv = findParent(v, parents);

      if (pu == pv)
        return edge;

      if (sizes[pu] < sizes[pv])
        swap(pu, pv);

      parents[pv] = pu;
      sizes[pu] += sizes[pv];
    }
    return {-1, -1};
  }
 private:
  int findParent(int node, vector<int>& parents) {
    while (parents[node] != node) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
};

int main() {
  Solution s;
  
  return 0;
}
