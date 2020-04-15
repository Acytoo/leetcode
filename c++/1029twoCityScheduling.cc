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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Greedy
class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int res = 0;
    const int n = costs.size(), half = n >> 1;
    sort(costs.begin(), costs.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[0] - a[1] < b[0] - b[1];
         });

    for (int i=0; i<n; ++i)
      res += i < half? costs[i][0]: costs[i][1];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
