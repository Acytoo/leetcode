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
  int reachableNodes(vector<vector<int>>& edges, int M, int N) {
    int res = 0;
    unordered_map<int, unordered_map<int, int>> graph;
    vector<bool> visited(N);
    priority_queue<pair<int, int>> pq;
    pq.push({M, 0});
    for (auto &edge : edges) {
      graph[edge[0]][edge[1]] = edge[2];
      graph[edge[1]][edge[0]] = edge[2];
    }
    while (!pq.empty()) {
      auto t= pq.top(); pq.pop();
      int move = t.first, cur = t.second;
      if (visited[cur]) continue;
      visited[cur] = true;
      ++res;
      for (auto &a : graph[cur]) {
        if (move > a.second && !visited[a.first]) {
          pq.push({move - a.second - 1, a.first});
        }
        graph[a.first][cur] -= min(move, a.second);
        res += min(move, a.second);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
