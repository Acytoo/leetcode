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
  int maxAbsoluteSum(vector<int>& nums) {
    int premin = 0, premax = 0, res = 0, sum = 0;
    for (const int a: nums) {
      sum += a;
      res = max({res, abs(sum - premin), abs(sum - premax)});
      premax = max(premax, sum);
      premin = min(premin, sum);
    }
    return res;
  }
};

class Solution1 {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    vector<int> sums(nums.size());
    partial_sum(nums.begin(), nums.end(), sums.begin());
    int premin = 0, premax = 0;
    int res = 0;  // empty subarray has sum equals to 0
    for (int i = 0, n = nums.size(); i < n; ++i) {
      res = max({res, abs(sums[i] - premin), abs(sums[i] - premax)});
      premax = max(premax, sums[i]);
      premin = min(premin, sums[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
