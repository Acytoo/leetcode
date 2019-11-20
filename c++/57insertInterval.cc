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
// solution 1: insert first, the use merge function from problem.56
// solution 2: find the position to insert the interval
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> left, right;

    for (const auto& interval : intervals) {

      if (interval[1] < newInterval[0]) {
        left.push_back(interval);
      } else if (newInterval[1] < interval[0]) {
        right.push_back(interval);
      } else {  // insert new interval here
        newInterval[0] = min(interval[0], newInterval[0]);
        newInterval[1] = max(interval[1], newInterval[1]);
      }
    }
    vector<vector<int>> res(move(left));
    res.emplace_back(newInterval);
    res.insert(res.end(), right.begin(), right.end());
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{1,2},{3,5},{6,7},{8,10},{12,16}};
  vector<int> b = {4,8};
  for (const auto& i : s.insert(a, b)) {
    for (const auto& j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
