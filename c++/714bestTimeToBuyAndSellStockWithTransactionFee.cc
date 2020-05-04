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

using namespace std;
// DP
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    const int n = prices.size();
    int hold = -prices[0], sold = 0;
    for (int i=1; i<n; ++i) {
      int tmp = hold;
      hold = max(hold, sold - prices[i]);
      sold = max(sold, tmp + prices[i] - fee);
    }
    return sold;
  }
};

class Solution_dummy {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    const int n = prices.size();
    int hold = -prices[0], sold = 0;
    for (int i=1; i<n; ++i) {
      int hold1 = max(hold, sold - prices[i]),
          sold1 = max(sold, hold + prices[i] - fee);
      hold = hold1;
      sold = sold1;
    }
    return sold;
  }
};

class Solution1 {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    const int n = prices.size();
    vector<int> hold (n), sold (n);
    hold[0] = -prices[0];
    for (int i=1; i<n; ++i) {
      hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
      sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
    }
    return sold.back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
