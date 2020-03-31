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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int res = 0;
    const int n = grid.size();
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j) {
        if (grid[i][j] > 0) res += (grid[i][j]<<2) + 2;
        if (i > 0) res -= min(grid[i][j], grid[i-1][j]) << 1;
        if (j > 0) res -= min(grid[i][j], grid[i][j-1]) << 1;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
