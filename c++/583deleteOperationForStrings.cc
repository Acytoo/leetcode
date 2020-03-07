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
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    if (m==0)
      return n;
    if (n==0)
      return m;
    int lcs2 = longestCommonSubsequence(word1, word2) << 1;
    return m+n-lcs2;
  }
 private:
  // lcs from leetcode 1143
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
  
  return 0;
}
