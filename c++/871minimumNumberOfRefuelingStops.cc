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

// 1 <= target, startFuel, stations[i][1] <= 10^9
// 0 <= stations.length <= 500
// 0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target

/*
DP
计算路过某个数量的加油站，所能达到的最远距离

dp[0]:用初始油量所能达到的最远距离
dp[1]:在一个加油站加油后，所能达到的最远距离
dp[2]:在2个加油站加油后，所能到达的最远距离
dp[i] = max(dp[i], dp[i - 1] + stations[j][1]), if station j can be reached


*/

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if (target - startFuel <= 0) return 0;

    const int n = stations.size();
    vector<long> dp (n + 1);
    dp[0] = startFuel;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j >= 1; --j)
        if (dp[j - 1] >= stations[i][0])
          dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
    for (int i = 0; i <= n; ++i)
      if (dp[i] >= target) return i;
    return -1;
  }
};

class Solution_old {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int fuelNeeded = target - startFuel;
    if (fuelNeeded <= 0) return 0;

    vector<long> dp (stations.size() + 1, startFuel);
    for (int i = 0, n = stations.size(); i < n; ++i) {
      for (int j = i; j >= 0 && dp[j] >= stations[i][0]; --j) {
        dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
      }
    }
    for (int i = 0, n = stations.size(); i <= n; ++i)
      if (dp[i] >= target) return i;
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
