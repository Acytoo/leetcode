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
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int res = intervals.size();
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                                               if (a[0] != b[0])
                                                 return a[0] < b[0];
                                               return a[1] > b[1];
                                             });
    int close = -1;
    for (auto i: intervals)
      if (i[1] <= close)
        --res;
      else
        close = i[1];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
