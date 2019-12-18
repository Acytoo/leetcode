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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    // Sort these balloons by their ends
    sort(points.begin(), points.end(),
         [&](const vector<int>& a, const vector<int>& b){return a[1] < b[1];} );
    int right = points[0][1];
    int res = 1;
    for (const auto& point: points) {
      if (right < point[0]) {
        ++res;
        right = point[1];
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{1,2}, {5, 9}, {1, 7}};
  cout << s.findMinArrowShots(a) << endl;
  return 0;
}
