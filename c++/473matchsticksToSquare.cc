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
  bool makesquare(vector<int>& nums) {
    const int n = nums.size();
    if (n < 4) return false;
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 4 != 0) return false;
    const int target = sum / 4;
    vector<int> sides (4);
    sort(nums.rbegin(), nums.rend());

    function<bool(int)> helper =
        [&] (const int idx) {
          if (idx >= n)
            return sides[0] == target && sides[1] == target && sides[2] == target;

          for (int i = 0; i < 4; ++i) {
            if (sides[i] + nums[idx] > target) continue;
            sides[i] += nums[idx];
            if (helper(idx + 1)) return true;
            sides[i] -= nums[idx];
          }
          return false;
        };
    return helper(0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
