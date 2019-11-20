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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// The given intervals are not sorted...
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
    vector<vector<int>> res;
    int i = -1;
    for (const auto& interval : intervals) {
      if (res.empty() || res[i][1] < interval[0]) {  // res.end < new interval.start
        res.push_back(interval);
        ++i;
      } else {
        res[i][1] = max(res[i][1], interval[1]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
