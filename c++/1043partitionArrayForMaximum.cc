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
  int maxSumAfterPartitioning(vector<int>& A, int K) {
    int n = A.size();
    vector<int> dp (n+1, 0);
    for (int i=1; i<=n; ++i) {
      int m = INT_MIN;
      for (int k=1; k<=min(K, i); ++k) {
        m = max(m, A[i-k]);
        dp[i] = max(dp[i], dp[i-k]+m*k);
      }
    }
    return dp.back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
