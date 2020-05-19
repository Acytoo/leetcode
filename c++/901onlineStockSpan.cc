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
    dp_.clear();
    prices_.clear();
  }

  int next(int price) {
    if (prices_.empty() || price < prices_.back()) {
      prices_.emplace_back(price);
      dp_.emplace_back(1);
      return 1;
    }
    int i = dp_.size() - 1;
    while (i >= 0 && prices_[i] <= price) i -= dp_[i];
    dp_.emplace_back(dp_.size() - i);
    prices_.emplace_back(price);
    return dp_.back();
  }
 private:
  vector<int> dp_, prices_;
};

class StockSpanner1 {  // TLE
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
