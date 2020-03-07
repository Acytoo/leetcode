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
// subarray: consecutive, lcs kind
class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size(), res = 0;
    vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (A[i] == B[j]) {
          dp[i+1][j+1] = dp[i][j] + 1;
          res = max(res, dp[i+1][j+1]);
        }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
