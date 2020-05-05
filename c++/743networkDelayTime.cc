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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Dijkstra, Bellman-Ford, Floyd-Warshall
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<uint32_t> receive (N + 1, INT_MAX);
    receive[K] = 0;
    for (int i = 1; i <= N; ++i)
      for (const auto &time: times)
        receive[time[1]] = min(receive[time[1]], receive[time[0]] + time[2]);
    int res = *max_element(receive.begin() + 1, receive.end());
    return res == INT_MAX? -1: res;
  }
};


class Solution_WRONG {
  // DFS
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<int>> g (N + 1, vector<int> (N + 1));
    for (const auto &time: times)
      g[time[0]][time[1]] = time[2];

    vector<int> receive(N + 1, INT_MAX);

    function<void(int, int)> dfs =
        [&] (int cur_node, int cur_time) {
          if (cur_time < receive[cur_node]) {  // update
            receive[cur_node] = cur_time;
            for (int i = 1; i <= N; ++i)
              if (g[cur_node][i]) dfs(i, cur_time + g[cur_node][i]);
          }  // wrong, cur_time > receive[cur_node], but receive[next_node] < receive[cur_node] + cur_time
        };

    dfs(K, 0);
    int res = *max_element(receive.begin() + 1, receive.end());
    return res == INT_MAX? -1: res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{2,1,1},{2,3,1},{3,4,1}, {4,3,2}};
  a = {{3,5,78},{2,1,1},{1,3,0},{4,3,59},{5,3,85},{5,2,22},{2,4,23},{1,4,43},{4,5,75},{5,1,15},{1,5,91},{4,1,16},{3,2,98},{3,4,22},{5,4,31},{1,2,0},{2,5,4},{4,2,51},{3,1,36},{2,3,59}};
  cout << s.networkDelayTime(a, 5, 5) << endl;
  return 0;
}
