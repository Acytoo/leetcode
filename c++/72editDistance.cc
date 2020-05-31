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
  int minDistance(string word1, string word2) {
    const int m = word1.size(), n = word2.size();
    vector<vector<int>> dp (m + 1, vector<int> (n + 1));
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int i = 0; i <= n; ++i) dp[0][i] = i;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        int op = word1[i - 1] == word2[j - 1]? 0: 1;
        dp[i][j] = min(dp[i -1][j - 1] + op, min(dp[i][j - 1], dp[i -1][j]) + 1);
      }
    return dp.back().back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
