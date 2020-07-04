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
// From huahua
class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    constexpr int kMod = 1e9  + 7;
    const int n = nums.size();
    sort(nums.begin(), nums.end());  // order doesn't matter
    vector<int> pows(n + 1, 1);
    for (int i = 1; i <= n; ++i) pows[i] = (pows[i - 1] << 1) % kMod;
    int res = 0;
    for (int i = 0, j = n - 1; i <= j; ++i) {
      while (i <= j && nums[i] + nums[j] > target) --j;
      if (i > j) continue;
      res = (res + pows[j - i]) % kMod;
    }
    return res;
  }
};

class Solution_Runtime_error {  // out of range long long
 public:
  int numSubseq(vector<int>& nums, int target) {
    constexpr int kMod = 1e9  + 7;
    long long res = 0;
    sort(nums.begin(), nums.end());  // order doesn't matter
    for (int i = 0, n = nums.size(); i < n; ++i) {
      for (int j = n - 1; j >= i; --j) {
        if (nums[i] + nums[j] > target) continue;
        if (i == j)
          res += 1;
        else
          res = (res + static_cast<long long>(pow(2, (j - i - 1)))) % kMod;
      }
    }
    return res % kMod;
  }
};

int main() {
  Solution s;
  
  return 0;
}
