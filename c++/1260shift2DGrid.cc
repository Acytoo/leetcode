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
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    const int m = grid.size()-1, n = grid[0].size()-1;
    while (k--) {
      int last = grid[m][n];
      for (int i=m; i>=0; --i)
        for (int j=n; j>=0; --j) {
          if (i==0 && j==0)
            grid[0][0] = last;
          else if (j == 0)
            grid[i][0] = grid[i-1][n];
          else
            grid[i][j] = grid[i][j-1];;
        }
    }
    return grid;
  }
};

int main() {
  Solution s;
  
  return 0;
}
