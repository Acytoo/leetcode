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
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> res (m, vector<int> (n, INT_MAX-123));  // INT_MAX + 1 is over flow, so make it smaller
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        if (matrix[i][j] == 0) {
          res[i][j] = 0;
          continue;
        }
        if (i) res[i][j] = min(res[i][j], res[i-1][j] + 1);
        if (j) res[i][j] = min(res[i][j], res[i][j-1] + 1);
      }
    --m; --n;
    for (int i=m; i>=0; --i)
      for (int j=n; j>=0; --j)
        if (res[i][j] != 0) {
          if (i<m) res[i][j] = min(res[i][j], res[i+1][j] + 1);
          if (j<n) res[i][j] = min(res[i][j], res[i][j+1] + 1);
        }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
