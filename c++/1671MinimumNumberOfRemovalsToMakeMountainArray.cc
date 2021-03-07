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
  int minimumMountainRemovals(vector<int>& nums) {
    const int n = nums.size();
    vector<int> l(n, 1), r(n, 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          l[i] = max(l[i], l[j] + 1);
    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j > i; --j)
        if (nums[i] > nums[j])
          r[i] = max(r[i], r[j] + 1);
    int res = n;
    for (int i = 0; i < n; ++i) {
      if (l[i]  == 1 || r[i] == 1) continue;
      res = min(res, n - (l[i] + r[i] - 1));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
