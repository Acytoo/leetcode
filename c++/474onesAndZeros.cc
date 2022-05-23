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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (const string &str : strs) {
      int ones = 0;
      for (const char c : str) ones += (c == '1');
      int zeros = str.size() - ones;
      for (int i = m; i >= zeros; --i)
        for (int j = n; j >= ones; --j)
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }
    return dp.back().back();
  }
};

class Solution_OLD {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
    for (const string& str: strs) {
      bitset<600> s (str);
      int len1 = s.count(), len0 = str.size() - len1;
      for (int i=m; i>=len0; --i)
        for (int j=n; j>=len1; --j)
          dp[i][j] = max(dp[i][j], dp[i-len0][j-len1]+1);
    }
    return dp[m][n];
  }
};

int main() {
  Solution s;
  
  return 0;
}
