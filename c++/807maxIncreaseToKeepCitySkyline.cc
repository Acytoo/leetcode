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
class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    const int n = grid.size();
    int res = 0;
    vector<int> row (n), col (n);
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j) {
        row[i] = max(row[i], grid[i][j]);
        col[j] = max(col[j], grid[i][j]);
      }
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j)
        res += min(row[i], col[j]) - grid[i][j];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
