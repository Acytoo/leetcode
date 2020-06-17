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
class Solution {  // Accepted, 8 ms, faster than 88.76%, 9.9 mb, less than 100% ...
 public:
  vector<int> finalPrices(vector<int>& prices) {
    const int n = prices.size();
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
      int j = i;
      while (++j < n) if (prices[j] <= prices[i]) break;
      if (j == n)
        res.emplace_back(prices[i]);
      else
        res.emplace_back(prices[i] - prices[j]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
