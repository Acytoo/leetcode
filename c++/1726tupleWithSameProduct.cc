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
// [(a, b), (c, d)]: (a, b) & (b, a): *2; (c, d) & (d, c): *2; (ab, cd) & (cd, ab) *2 ==> *2*2*2 = *8
// res: c(n, 2) * 8 ==> n * (n - 1) * 4
class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int i = 0, n = nums.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        ++m[nums[i] * nums[j]];
    int res = 0;
    for (auto it = m.begin(); it != m.end(); ++it)
      if (it->second > 1)
        res += it->second * (it->second - 1) * 4;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
