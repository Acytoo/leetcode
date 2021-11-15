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
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    const int n = prices.size();
    vector<int> buy(n), sell(n);
    buy[0] = -prices[0];
    int res = 0;
    for (int i = 1; i < n; ++i) {
      buy[i] = max(sell[i - 1] - prices[i], buy[i - 1]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
      res = max(res, sell[i]);
    }
    return res;
  }
};

// You can sell in the morning and buy back later the same day
class Solution_OLD {
 public:
  int maxProfit(vector<int>& prices) {
    int res = 0, i = -1, n = prices.size() - 1;  // n: last index
    if (n < 0) return 0;

    while (++i < n)
      res += max(prices[i+1] - prices[i], 0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
