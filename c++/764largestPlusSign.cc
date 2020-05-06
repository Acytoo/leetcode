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
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    int dp[N][N];
    memset(dp, 127, sizeof(dp));
    for (const auto &mine: mines) dp[mine[0]][mine[1]] = 0;

    for (int i = 0; i < N; ++i) {
      int l = 0, r = 0, u = 0, d = 0;
      for (int j = 0, k = N - 1; j < N; ++j, --k) {
        dp[i][j] = min(dp[i][j], l = dp[i][j]? l + 1: 0);
        dp[j][i] = min(dp[j][i], u = dp[j][i]? u + 1: 0);
        dp[i][k] = min(dp[i][k], r = dp[i][k]? r + 1: 0);
        dp[k][i] = min(dp[k][i], d = dp[k][i]? d + 1: 0);
      }
    }

    int res = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (res < dp[i][j]) res = dp[i][j];
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a  = {{0, 0}};
  cout << s.orderOfLargestPlusSign(7, a) << endl;
  return 0;
}
