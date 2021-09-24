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
// Greedy, sorting
class Solution {
 public:
  int minDifference(vector<int>& nums) {
    if (nums.size() <= 3) return 0;
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    return min(min({nums[r] - nums[l + 3], nums[r - 1] - nums[l + 2], nums[r - 2] - nums[l + 1]}),
               nums[r - 3] - nums[l]);
  }
};

int main() {
  Solution s;
  
  return 0;
}
