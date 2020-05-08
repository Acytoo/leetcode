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
  int maxProfitAssignment(vector<int>& difficulty,
                          vector<int>& profit, vector<int>& worker) {
    const int n = profit.size();
    vector<pair<int, int>> jobs;
    jobs.reserve(n);
    for (int i = 0; i < n; ++i)
      jobs.emplace_back(difficulty[i], profit[i]);  // difficulty --> profit
    sort(jobs.begin(), jobs.end(), [] (const pair<int, int> &a, const pair<int, int> &b) {
                                     return a.first != b.first? a.first < b.first: a.second > b.second;
                                   });

    int cur_max_profit = jobs[0].second;
    for (auto &job: jobs)
      if (cur_max_profit < job.second)
        cur_max_profit = job.second;
      else
        job.second = cur_max_profit;

    int res = 0;
    for (const int w: worker) {
      auto it = lower_bound(jobs.begin(), jobs.end(), make_pair(w, INT_MAX));
      if (it == jobs.begin()) {
        if (it->first == w)
          res += it->second;
      } else {
        res += (it - 1)->second;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
