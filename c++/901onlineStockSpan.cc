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
class StockSpanner {
 public:
  StockSpanner() {
  }

  int next(int price) {
    int res = 1;
    while (!s_.empty() && s_.top().first <= price) {
      res += s_.top().second;
      s_.pop();
    }
    s_.emplace(price, res);
    return res;
  }
  stack<pair<int, int>> s_;  // price -> span
};

int main() {
  Solution s;
  
  return 0;
}
