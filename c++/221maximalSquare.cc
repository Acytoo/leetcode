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


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty())
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sizes(m, vector<int>(n, 0));
    int res = 0;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        sizes[i][j] = matrix[i][j] - '0';
        if (sizes[i][j] == 0)
          continue;
        if (i == 0 || j == 0) {
          // pass
        } else {
          sizes[i][j] = min(min(sizes[i-1][j-1], sizes[i-1][j]), sizes[i][j-1]) + 1;
        }
        res = max(res, sizes[i][j]*sizes[i][j]);
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
