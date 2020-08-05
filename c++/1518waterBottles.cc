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
  int numWaterBottles(int numBottles, int numExchange) {
    function<int(int, int)> helper =
        [&] (int left, int rem) -> int {
          if ((left + rem) < numExchange) return left;
          int exchange = (left + rem) / numExchange;
          return left + helper(exchange, (left + rem) - (exchange * numExchange));
        };
    return helper(numBottles, 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
