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
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp (n1, vector<int> (n2));
    dp[0][0] = nums1[0] * nums2[0];
    for (int i = 1; i < n1; ++i) dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
    for (int i = 1; i < n2; ++i) dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
    for (int i = 1; i < n1; ++i)
      for (int j = 1; j < n2; ++j)
        dp[i][j] = max({
            dp[i - 1][j],
            dp[i][j - 1],
            max(0, dp[i -1][j - 1]) + nums1[i] * nums2[j]
          });
    return dp.back().back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
