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
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res (n + 1);
    for (const auto &b: bookings) {
      res[b[0] - 1] += b[2];
      res[b[1]] -= b[2];
    }
    res.pop_back();
    for (int i = 1; i < n; ++i) res[i] += res[i -1];
    return res;
  }
};

class Solution_TLE {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res (n);
    for (const auto &b: bookings)
      for (int i = b[0] - 1; i < b[1]; ++i)
        res[i] += b[2];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
