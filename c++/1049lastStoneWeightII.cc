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
  int lastStoneWeightII(vector<int>& stones) {
    const int n = stones.size();
    if (n == 1) return stones[0];

    int res = INT_MAX;
    unordered_set<int> s;
    s.insert(stones[0]);
    s.insert(-stones[0]);
    for (int i = 1; i < n; ++i) {
      unordered_set<int> bk;
      for (const int stone: s) {
        bk.insert(stone + stones[i]);
        bk.insert(stone - stones[i]);
      }
      swap(s, bk);
    }

    for (const int stone: s) res = min(res, abs(stone));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
