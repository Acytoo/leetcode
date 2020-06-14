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

// Greedy
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    if (n <= 1) return 0;
    sort(intervals.begin(), intervals.end());
    int res = 0, last_end = intervals[0][1];
    for (int i = 1; i < n; ++i)
      if (intervals[i][0] < last_end) {
        ++res;
        last_end = min(last_end, intervals[i][1]);
      } else {
        last_end = intervals[i][1];
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
