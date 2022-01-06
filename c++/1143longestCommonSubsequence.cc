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
  int longestCommonSubsequence(string text1, string text2) {
    const int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (text1[i] == text2[j])
          dp[i + 1][j + 1] = dp[i][j] + 1;
        else
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    return dp[m][n];
  }
};


// lcs
class Solution_OLD {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (text1[i] == text2[j])
          dp[i+1][j+1] = dp[i][j] + 1;
        else
          dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    return dp[m][n];
  }
};

int main() {
  Solution s;
  string a = "abcba",
         b =  "abcbcba";
  cout << s.longestCommonSubsequence(a, b) << endl;
  return 0;
}
