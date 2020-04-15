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
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    const int m = A.size(), n = B.size();
    vector<vector<int>> dp (m+1, vector<int> (n+1));
    for (int i=1; i<=m; ++i)
      for (int j=1; j<=n; ++j)
        if (A[i-1] == B[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    return dp[m][n];
  }
};

int main() {
  Solution s;
  
  return 0;
}
