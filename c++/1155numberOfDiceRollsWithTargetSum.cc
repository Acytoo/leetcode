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
// DP: dp[i][j]: number of possible ways for i dices face up sum j
class Solution {
 public:
  int numRollsToTarget(int d, int f, int target) {
    vector<vector<int>> dp (d+1, vector<int> (target+1));
    const int kMod = 1e9 + 7;
    dp[0][0] = 1;

    for (int i=1; i<=d; ++i)   // num of dices
      for (int j=1; j<=f; ++j)  // face up num
        for (int k=j; k<=target; ++k)  // possible sum
          dp[i][k] = (dp[i][k] + dp[i-1][k-j]) % kMod;
    return dp.back()[target];
  }
};

int main() {
  Solution s;
  
  return 0;
}
