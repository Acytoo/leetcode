#include <iostream>
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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= k <= 1e5
class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    const int kMod = 1e9 + 7;
    function<long(int)> maxSum =
        [&arr] (int k) {
          long sum = 0L, res = 0L;
          while (k--)
            for (const int a: arr) {
              if (-sum <= a) {
                sum += a;
                res = max(res, sum);
              } else {
                sum = 0L;
              }
            }
          return res;
        };

    if (k < 3) return maxSum(k) % kMod;

    long res1 = maxSum(1), res2 = maxSum(2),
          sum = accumulate(arr.begin(), arr.end(), 0);
    return max({res1, res2, res2+sum*(k-2)}) % kMod;
  }
};

int main() {
  Solution s;
  
  return 0;
}
