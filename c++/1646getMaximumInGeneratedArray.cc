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

// Only odd position can be result
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Brute force
class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    vector<int> nums (n + 1);
    nums[0] = 0;
    nums[1] = nums[2] = 1;
    int res = 2;
    for (int i = 2; i <= n; ++i)
      if (i & 1) {
        nums[i] = nums[i >> 1] + nums[(i >> 1) + 1];
        res = max(res, nums[i]);
      } else {
        nums[i] = nums[i >> 1];
      }
    return res;
  }
};

class Solution_WRONG {
public:
  int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    if (!(n & 1)) return getMaximumGenerated(n - 1);
    int res = 0;
    function<int(int)> helper =
      [&] (const int a) -> int {
        if (a == 0) return 0;
        if (a <= 2) return 1;
        if (a & 1) {
          return helper(a >> 1) + helper((a >> 1) + 1);
        } else {
          return helper(a >> 1);
        }
      };
    return helper(n);
  }
};

int main() {
  Solution s;
  int a = 0;
  while (cin >> a)
    cout << s.getMaximumGenerated(a) << endl;
  return 0;
}
