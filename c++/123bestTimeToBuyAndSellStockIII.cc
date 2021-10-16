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
// DP
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    const int n = prices.size();
    vector<vector<int>> global(n, vector<int> (3, 0)), local(n, vector<int> (3, 0));
    for (int i = 1; i < n; ++i) {
      const int diff = prices[i] - prices[i - 1];
      for (int j = 1; j < 3; ++j) {
        local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff;
        global[i][j] = max(global[i - 1][j], local[i][j]);
      }
    }
    return global[n - 1][2];
  }
};

class Solution1 {  // From leetcode
 public:/*
    ===========  GENERAL IDEA FOR ALL BUY & SELL STOCK PROBLEMS   =========================

    Let
    T(i,k,b) => maximum profit of i-th day, given k transactions are allowed, and we own b stocks after the actions.

    Base cases =>
    T(i, 0, 0) = 0
    T(-1, k, 0) = 0
    T(i, 0, 1) = impossible (-inf)
    T(-1, k, 1) = impossible (-inf)

    Actions we can take =>
    Rest => T(i, k, b) = T(i-1, k, b)
    Sell (happens to make b = 1) => T(i, k, 0) = T(i-1, k, 1) + A[i]
    Buy (happens to make b = 0) => T(i ,k, 1) = T(i-1, k-1, 0) - A[i]

    Hence,
    T(i, k, 0) = max(rest, sell) = max( T(i-1, k, 0), T(i-1, k, 1) + A[i] )
    T(i, k, 1) = max(rest, buy) = max( T(i-1, k, 1), T(i-1, k-1, 0) - A[i] )

    Since we sell the stock at the end, the answer is T(p, k, 0), p being len(A)-1.

    From here, we can use suitable values of k for different cases.

    A. Best Time to Buy and Sell Stock      =>      k is 1.
    B. Best Time to Buy and Sell Stock II   =>      k is inf
    C.
    ===========================================================================================
        */

  int maxProfit(vector<int>& prices) {
    /*

      i is initially -1
      k = 2

      Variable T_ikb stores value of T(i,k,b)
    */
    int T_i00 = 0, T_i01 = INT_MIN; // Base case, won't change
    int T_i10 = 0, T_i11 = INT_MIN; // k = 1, can change on basis of i
    int T_i20 = 0, T_i21 = INT_MIN; // k = 2, can change on basis of i
    // Hence we will update for k = 1 and 2.
    for(int i = 0, stop = prices.size(); i < stop; ++i){
      T_i20 = max(T_i20, T_i21 + prices[i]);
      T_i21 = max(T_i21, T_i10 - prices[i]);
      T_i10 = max(T_i10, T_i11 + prices[i]);
      T_i11 = max(T_i11, T_i00 - prices[i]);
    }
    return T_i20;
  }
};

class Solution_TLE2 {  // search, TLEEEE
 public:
  int maxProfit(vector<int>& prices) {
    int res = 0;
    const int n = prices.size();
    function<void(int, int, int, int, int)> search = [&] (int day, int status, int opt, int buy_price, int cur) {
      if (opt <= 0) return;
      if (day >= n) return;
      const int nextday = day + 1;
      if (status == 1) {  // hold stock, do nothing or sell
        if (prices[day] <= buy_price && (nextday < n && prices[nextday] < prices[day])) {  // prune
          search(nextday, status, opt, buy_price, cur);  // do nothing
          return;
        }
        search(nextday, status, opt, buy_price, cur);  // do nothing
        // or sell
        cur += prices[day];
        buy_price = INT_MAX;
        opt -= 1;
        status = 0;
        res = max(res, cur);
        search(nextday, status, opt, buy_price, cur);
      } else {  // empty, do nothing or buy
        search(nextday, status, opt, buy_price, cur);
        if (nextday < n && prices[nextday] < prices[day]) return;  // prune
        cur -= prices[day];
        buy_price = prices[day];
        status = 1;
        search(nextday, status, opt, buy_price, cur);
      }
    };
    search(0, 0, 2, 0, 0);
    return res;
  }
};


class Solution_TLE {  // TLE in 201 case
 public:
  int maxProfit(vector<int>& prices) {
    int res = 0;
    const int n = prices.size();
    function<void(int, int, int, int, int)> search = [&] (int day, int status, int opt, int buy_price, int cur) {
      if (opt <= 0) return ;
      if (day >= n) {
        res = max(res, cur);
        return ;
      }
      if (status == 1) {  // hold stock, do nothing or sell
        if (prices[day] <= buy_price) {  // prune
          search(day + 1, status, opt, buy_price, cur);  // do nothing
          return;
        }
        search(day + 1, status, opt, buy_price, cur);  // do nothing
        // or sell
        cur += prices[day];
        buy_price = INT_MAX;
        opt -= 1;
        status = 0;
        res = max(res, cur);
        search(day + 1, status, opt, buy_price, cur);
      } else {  // empty, do nothing or buy
        search(day + 1, status, opt, buy_price, cur);
        cur -= prices[day];
        buy_price = prices[day];
        status = 1;
        search(day + 1, status, opt, buy_price, cur);
      }
    };
    search(0, 0, 2, 0, 0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
