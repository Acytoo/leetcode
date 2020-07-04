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
  int longestSubarray(vector<int>& nums) {
    int res = 0, sum = 0;
    for (int l = 0, r = 0, n = nums.size(); r < n; ++r) {
      sum += nums[r];
      while (l < r && sum < r - l) sum -= nums[l++];
      res = max(res, r - l);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
