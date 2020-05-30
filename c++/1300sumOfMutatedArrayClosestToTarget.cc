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
  int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    const int n = arr.size();
    vector<int> prefix (n + 1);
    for (int i = 1; i <= n; ++i) prefix[i] = prefix[i -1] + arr[i - 1];
    int l = 1, r = arr.back(), res = 0, diff = target;
    auto getSum =
        [&] (int threshold) {
          int rank = lower_bound(arr.begin(), arr.end(), threshold) - arr.begin();
          return prefix[rank] + (n - rank) * threshold;
        };
    while (l <= r) {
      int m = (l + r) >> 1;
      int sum = getSum(m);
      int cur_diff = abs(sum - target);
      if (cur_diff < diff) {
        diff = cur_diff;
        res = m;
      } else if (cur_diff == diff && m < res) {
        res = m;
      }
      if (sum < target)
        l = m + 1;
      else if (target < sum)
        r = m - 1;
      else
        return m;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
