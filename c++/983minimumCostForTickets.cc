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
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int dp[366];
    memset(dp, 0, sizeof(dp));

    for (int i = 1, j = 0, n = days.size(); i < 366; ++i) {
      if (j >= n) break;
      if (i != days[j]) {
        dp[i] = dp[i - 1];
        continue;
      }
      dp[i] = dp[i - 1] + costs[0];
      dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
      dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
      ++j;
    }

    return dp[days.back()];
  }
};

class Solution1 {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int dp[366], travel[366];
    memset(dp, 0, sizeof(dp));
    memset(travel, 0, sizeof(dp));

    for (const int day: days) travel[day] = 1;
    for (int i = 1; i < 366; ++i) {
      if (travel[i] == 0) {
        dp[i] = dp[i - 1];
        continue;
      }
      dp[i] = dp[i - 1] + costs[0];
      dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
      dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
    }

    return dp[365];
  }
};

int main() {
  Solution s;
  vector<int> a = {1}, b = {1};
  s.mincostTickets(a, b);
  return 0;
}
