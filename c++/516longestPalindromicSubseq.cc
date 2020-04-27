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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// DP, from huahua
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.size();
    vector<vector<int>> dp (n, vector<int> (n));
    for (int l=1; l<=n; ++l)
      for (int i=0, stop=n-l; i<=stop; ++i) {
        int j = i + l - 1;
        if (i == j) {
          dp[i][j] = 1;
          continue;
        }
        if (s[i] == s[j])
          dp[i][j] = dp[i+1][j-1] + 2;
        else
          dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
      }
    return dp[0][n-1];
  }
};

int main() {
  Solution s;
  
  return 0;
}
