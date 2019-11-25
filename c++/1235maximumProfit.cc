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

using namespace std;
// 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
// 1 <= startTime[i] < endTime[i] <= 10^9
// 1 <= profit[i] <= 10^4
// So the time complexity < O(n^2)
// DP problem, the variable is end time, iterate end time
// Sort jobs by the end time first

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    const int n = startTime.size();
    vector<vector<int>> jobs(n);
    for (int i=0; i<n; ++i)
      jobs[i] = {endTime[i], startTime[i], profit[i]};
    sort(jobs.begin(), jobs.end());

    int res = 0;
    map<int, int> dp{{0, 0}};           // end_time, max_profit
    for (const auto& job: jobs) {
      int p = prev(dp.upper_bound(job[1]))->second + job[2];
      if (p > rbegin(dp)->second) {
          dp[job[0]] = p;
      }
    }
  return dp.rbegin()->second;
  }
};


int main() {
  Solution s;
  // vector
  return 0;
}
