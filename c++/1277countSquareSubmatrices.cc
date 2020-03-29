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
  int countSquares(vector<vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp (m, vector<int> (n));
    int res = 0;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        dp[i][j] = matrix[i][j];
        if (i && j && dp[i][j])
          dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
        res += dp[i][j];
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
