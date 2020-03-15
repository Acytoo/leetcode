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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    // int m = grid.size(), n = grid[0].size();
    int res = 0;
    for (auto row: grid)
      for (auto ele: row)
        if (ele < 0)
          ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
