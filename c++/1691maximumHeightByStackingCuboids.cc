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
  int maxHeight(vector<vector<int>>& cuboids) {
    for (auto &c : cuboids) sort(c.rbegin(), c.rend());
    sort(cuboids.rbegin(), cuboids.rend());
    const int n = cuboids.size();
    vector<int> dp (n);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      dp[i] = cuboids[i][0];
      for (int j = 0; j < i; ++j) {
        if (cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]) {
          dp[i] = max(dp[i], dp[j] + cuboids[i][0]);
        }
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
