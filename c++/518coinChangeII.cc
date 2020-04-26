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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp (amount + 1);
    dp[0] = 1;
    for (const int coin: coins)
      for (int i=0, stop=amount-coin; i<=stop; ++i)
        dp[i+coin] += dp[i];
    return dp[amount];
  }
};

int main() {
  Solution s;
  
  return 0;
}
