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
// Greedy, O(nlogn)
class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int res = 0;
    for (auto it = costs.begin(); it != costs.end() && coins > 0; ++it) {
      if (*it > coins) break;
      ++res;
      coins -= *it;
    }
    return res;
  }
};

// From hqztrue, O(n)
const int L = 10000;
class Solution1 {
 public:
  int maxIceCream(vector<int>& _c, int C) {
    int *c = &_c[0], l = 0, r = _c.size();
    while (l < r) {
      int s = 0, mid = (l + r) / 2;
      nth_element(c + l, c + mid, c + r);
      for (int i = l; i <= mid && s <= C; i += L)
        s = accumulate(c + i, c + min(i + L, mid + 1), s);
      if (s > C)
        r = mid;
      else
        l = mid + 1, C -= s;
    }
    return l;
  }
};
int main() {
  Solution s;
  
  return 0;
}
