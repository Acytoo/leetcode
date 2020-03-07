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
class Solution1 {
 public:
  int numTrees(int n) {
    vector<int> dp (n+1);
    dp[0] = dp[1] = 1;
    for (int i=2; i<=n; ++i)
      for (int j=0; j<i; ++j)
        dp[i] += dp[j] * dp[i-j-1];
    return dp.back();
  }
};

class Solution {
 public:
  int numTrees(int n) {
    long res = 1;
    for (int i=n+1, stop=2*n; i<=stop; ++i)
      res = res * i / (i - n);
    return res / (n + 1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
