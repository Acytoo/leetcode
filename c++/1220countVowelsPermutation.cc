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
#include <numeric>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Another DP
class Solution {
 public:
  int countVowelPermutation(int n) {
    vector<vector<long>> dp(2, vector<long>(5, 1));  // a, e, i, o, u, and their pre
    constexpr int k_mod = 1e9+7;
    for (int i=2; i<=n; ++i) {

      dp[1][0] = (dp[0][1] + dp[0][2] + dp[0][4])            % k_mod;
      dp[1][1] = (dp[0][0] + dp[0][2])                       % k_mod;
      dp[1][2] = (dp[0][1] + dp[0][3])                       % k_mod;
      dp[1][3] = (dp[0][2])                                  % k_mod;
      dp[1][4] = (dp[0][2] + dp[0][3])                       % k_mod;

      dp[0][0] = dp[1][0];
      dp[0][1] = dp[1][1];
      dp[0][2] = dp[1][2];
      dp[0][3] = dp[1][3];
      dp[0][4] = dp[1][4];
    }
    return (dp[0][0]+dp[0][1]+dp[0][2]+dp[0][3]+dp[0][4]) % k_mod;
    // return accumulate(dp[0].begin(), dp[0].end(), 0) % k_mod;
  }
};

int main() {
  Solution s;
  cout << s.countVowelPermutation(158) << endl;
  return 0;
}
