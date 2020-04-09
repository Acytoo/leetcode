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
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    const int m = M.size(), n = M[0].size();
    vector<vector<int>> res (m, vector<int> (n)),
        dirs = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        int cur = M[i][j], cell_num = 1;
        for (const auto &dir: dirs) {
          int x = i + dir[0], y = j + dir[1];
          if (x<0 || x==m || y<0 || y==n) continue;
          cur += M[x][y];
          ++cell_num;
        }
        res[i][j] = cur / cell_num;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
