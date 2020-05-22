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
  int minScoreTriangulation(vector<int>& A) {
    const int n = A.size();
    vector<vector<int>> dp (n, vector<int> (n));
    for (int l = 2; l < n; ++l)
      for (int i = 0, stop = n - l; i < stop; ++i) {
        int j = i + l;
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
      }
    return dp.front().back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
