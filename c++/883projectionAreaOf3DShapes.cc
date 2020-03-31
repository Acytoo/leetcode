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
  int projectionArea(vector<vector<int>>& grid) {
    int res = 0;
    const int n = grid.size();
    for (int i=0; i<n; ++i) {
      int row_max = 0, col_max = 0;
      for (int j=0; j<n; ++j) {
        if (grid[i][j]) ++res;  // xy
        if (grid[i][j] > row_max) row_max = grid[i][j];
        if (grid[j][i] > col_max) col_max = grid[j][i];
      }
      res += row_max + col_max;  // yz, zx
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
