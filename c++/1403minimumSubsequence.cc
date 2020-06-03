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
  vector<int> minSubsequence(vector<int>& nums) {
    if (nums.size() == 1) return nums;

    sort(nums.rbegin(), nums.rend());
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    int prefix = nums[0], i = 0;
    vector<int> res {prefix};
    while (prefix <= sum - prefix) {
      res.emplace_back(nums[++i]);
      prefix += nums[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
