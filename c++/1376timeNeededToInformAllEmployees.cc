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

// 1 <= n <= 10^5
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    unordered_map<int, vector<int>> flow;  // manager -> employees
    for (int i = 0; i < n; ++i) flow[manager[i]].emplace_back(i);
    function<int(int)> dfs =
        [&] (const int source) -> int {
          if (flow.count(source) == 0) return 0;
          int res = 0;
          for (const int target: flow[source])
            res = max(res, dfs(target));
          return res + informTime[source];
        };
    return dfs(headID);
  }
};

int main() {
  Solution s;
  
  return 0;
}
