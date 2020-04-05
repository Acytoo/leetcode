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
// You can sell in the morning and buy back later the same day
class Solution {
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
