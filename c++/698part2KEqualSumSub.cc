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
// 1 <= k <= len(nums) <= 16
class Solution_same {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    sort(nums.rbegin(), nums.rend());
    return dfs(nums, sum/k, 0, k, 0);
  }
 private:
  bool dfs(const vector<int>& nums, int target, int cur, int k, int used) {
    if (k == 0) return used == (1<<nums.size())-1;
    for (int i=0, stop=nums.size(); i<stop; ++i) {
      if (used & (1<<i)) continue;
      int new_sum = cur + nums[i];
      if (new_sum > target) break;
      int new_used = used | (1<<i);
      if (new_sum == target && dfs(nums, target, 0, k-1, new_used)) return true;
      else if (dfs(nums, target, new_sum, k, new_used)) return true;
    }
    return false;
  }
};

class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    int target = sum / k;
    sort(nums.rbegin(), nums.rend());
    function<bool(int, int, int)> dfs =
             [&] (int cur, int k, int used) {
               // used: int type, but we use it's bits to represent whether that num in nums is used or not
               if (k == 0) return used == (1<<nums.size())-1;
               for (int i=0, stop=nums.size(); i<stop; ++i) {
                 if (used & (1<<i)) continue;
                 int new_sum = cur + nums[i];
                 if (new_sum > target) break;
                 int new_used = used | (1<<i);
                 if (new_sum == target && dfs(0, k-1, new_used)) return true;
                 else if (dfs(new_sum, k, new_used)) return true;
               }
               return false;
             };
    return dfs(0, k, 0);
  }
};

int main() {
  Solution s;
  vector<int> a = {4,5,3,2,5,5,5,1,5,5,5,5,3,5,5,2};
  // a = {4, 3, 2, 3, 5, 2, 1};
  cout << s.canPartitionKSubsets(a, 13) << endl;
  return 0;
}
