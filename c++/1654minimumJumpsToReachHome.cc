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

// 1 <= forbidden.length <= 1000
// 1 <= a, b, forbidden[i] <= 2000
// 0 <= x <= 2000
// All the elements in forbidden are distinct.
// Position x is not forbidden.
// 注意 loc > 8000 这个条件，可以走一步返回一步，a < b

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> been1, been2;
    for (const int f : forbidden) { been1.insert(f); been2.insert(f); }
    deque<pair<int, bool>> dq = {{0, true}};  // axis, can back
    int res = 0;
    while (!dq.empty()) {
      int sz = dq.size();
      while (--sz >= 0) {
        auto [loc, can] = dq.front(); dq.pop_front();
        if (loc == x) return res;
        if (loc > 8000) continue;
        if (been1.insert(loc + a).second)
          dq.emplace_back(loc + a, true);
        if (loc - b > 0 && can && been2.insert(loc - b).second)
          dq.emplace_back(loc - b, false);
      }
      ++res;
    }
    return -1;
  }
};


int main() {
  Solution s;
  
  return 0;
}
