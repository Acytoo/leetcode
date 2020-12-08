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

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();

class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int res = 0;
    for (const int num: nums) ++m[num];
    for (auto &[val, n]: m) {
      const int t = k - val;
      if (t == val) {
        res += (n >> 1);
        continue;
      }
      if (m.count(t) != 0) {
        const int cur = min(n, m[t]);
        n -= cur;
        m[t] -= cur;
        res += cur;
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
