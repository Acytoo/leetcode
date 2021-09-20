#include <iostream>
#include <sstream>
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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numDistinct(string s, string t) {
    const int m = s.size(), n = t.size();
    vector<vector<long>> dp (n + 1, vector<long> (m + 1));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        if (dp[i][j] > INT_MAX) dp[i][j] = 0;
      }
    return dp.back().back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
