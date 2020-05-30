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
class Cashier {
 public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices):
      n_(n), idx_(0) {
    for (int i = 0, stop = products.size(); i < stop; ++i)
      m_[products[i]] = prices[i];
    x_ = (100.0 - discount) / 100;
  }

  double getBill(vector<int> product, vector<int> amount) {
    double res = .0;
    for (int i = 0, stop = product.size(); i < stop; ++i)
      res += m_[product[i]] * amount[i];

    if (++idx_ == n_) {
      idx_ = 0;
      res *= x_;
    }
    return res;
  }
 private:
  int n_, idx_;
  double x_;
  unordered_map<int, int> m_;  // id --> price
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

int main() {
  Solution s;
  
  return 0;
}
