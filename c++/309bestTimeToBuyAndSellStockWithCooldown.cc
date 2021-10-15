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
// DP
// stock(money) held in day i : max(buy[i-1], cooldown[i-1]-prices[i])
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    const int n = prices.size();
    if (n <= 1) return 0;
    int hold[n], sold[n], cooldown[n];
    memset(hold, 0, sizeof sold);
    memset(sold, 0, sizeof sold);
    memset(cooldown, 0, sizeof sold);
    hold[0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      cooldown[i] = sold[i - 1];
      sold[i] = max(sold[i -1], hold[i - 1] + prices[i]);
      hold[i] = max(hold[i - 1], cooldown[i - 1] - prices[i]);
    }
    return max(sold[n - 1], cooldown[n - 1]);
  }
};




class Solution1_OLD {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0)
      return 0;
    vector<int> buy(n, 0), sell(n, 0), cooldown(n, 0);
    buy[0] = -prices[0];
    for (int i=1; i<n; ++i) {
      cooldown[i] = sell[i-1];
      sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
      buy[i] = max(buy[i-1], cooldown[i-1]-prices[i]);
    }
    return max(sell.back(), cooldown.back());
  }
};

// 滚动数组降维
class Solution_OLD {
 public:
  int maxProfit(vector<int>& p) {
    int sold = 0, rest = 0, hold = INT_MIN;
    for (const int price: p) {
      int prev_sold = sold;
      sold = hold + price;
      hold = max(hold, rest - price);
      rest = max(rest, prev_sold);
    }
    return max(rest, sold);
  }
};

int main() {
  Solution s;
  
  return 0;
}
