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

// distinct number 1 - 9
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    const int m = grid.size(), n = grid.back().size();
    if (m < 2 || n < 2) return 0;
    function<bool(int, int)> magic =
            [&] (const int x, const int y) -> bool {  // (x, y): top left corner
              if (grid[x + 1][y + 1] != 5) return false;
              int test = 0, num = 0;
              for (int i = x, stopi = x + 3; i < stopi; ++i)
                for (int j = y, stopj = y + 3; j < stopj; ++j) {
                  test ^= grid[i][j] ^ ++num;
                }
              if (test != 0) return false;

              int r1 = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
              int r2 = grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2];
              if (r1 != r2) return false;
              int r3 = grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2];
              if (r2 != r3) return false;
              int c1 = grid[x][y] + grid[x + 1][y] + grid[x + 2][y];
              if (c1 != r3) return false;
              int c2 = grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1];
              if (c2 != c1) return false;
              int c3 = grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2];
              if (c3 != c2) return false;
              int d1 = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
              if (d1 != c3) return false;
              int d2 = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];
              if (d2 != d1) return false;
              return true;
            };

    int res = 0;
    for (int i = 0, stopi = m - 2; i < stopi; ++i)
      for (int j = 0, stopj = n - 2; j < stopj; ++j)
        res += magic(i, j);
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{4,3,8,4},
                           {9,5,1,9},
                           {2,7,6,2}};
  a = {{5,5,5},{5,5,5},{5,5,5}};
  cout << s.numMagicSquaresInside(a) << endl;
  return 0;
}
