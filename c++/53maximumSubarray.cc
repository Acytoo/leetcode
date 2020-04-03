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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    const int n = nums.size();
    if (n == 0) return INT_MIN;
    int res = nums[0];
    for (int i=1; i<n; ++i) {
      nums[i] = nums[i-1] > 0? nums[i-1] + nums[i]: nums[i];
      res = max(res, nums[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
