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
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    int res = INT_MAX;
    // start point u -----> {end point v, weight w}
    unordered_map<int, vector<vector<int>>> m;
    for (const vector<int>& i: flights)
      m[i[0]].emplace_back(std::initializer_list<int>{i[1], i[2]});
    bitset<100> visited;
    visited[src] = 1;
    bool has_res = false;
    function<void(int, int, int, int, int&)> dfs =
        [&](int src, int dst, int cost, int k, int& res) {
          if (src == dst) {
            res = cost;
            has_res = true;
            return ;
          }
          if (k == 0)
            return ;
          for (const vector<int>& i: m[src]) {
            if (visited[i[0]] || cost+i[1] > res)
              continue;
            visited[i[0]] = 1;
            dfs(i[0], dst, cost+i[1], k-1, res);
            visited[i[0]] = 0;
          }
        };
    dfs(src, dst, 0, K+1, res);
    return has_res? res: -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{0,1,100},{1,2,100},{0,2,500}};
  cout << s.findCheapestPrice(3, a, 1, 2, 1) << endl;
  return 0;
}
