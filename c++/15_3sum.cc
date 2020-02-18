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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Dual pointer
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; ++i) {
      int j = i + 1;
      int k = n - 1;
      if (i!=0 && nums[i]==nums[i-1])
        continue;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          res.emplace_back(std::initializer_list<int>{nums[i], nums[j], nums[k]});
          ++j;
          while (j<k && nums[j]==nums[j-1])
            ++j;
          --k;
          while (j<k && nums[k]==nums[k+1])
            --k;
        } else if (sum < 0) {
          ++j;
        } else {
          --k;
        }
      }
    }
    return res;
  }
};
// TLE
class Solution1 {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; ++i) {
      if (i!=0 && nums[i]==nums[i-1])  // nums[i] can equal to nums[j], but duplicate nums[i] is now allowed
        continue;
      unordered_map<int, int> m;  // value, index
      for (int j=i+1; j<n; ++j) {
        int target = -nums[i] - nums[j];
        if (m.find(target) != m.end()) {  // one
          res.emplace_back(std::initializer_list<int>{nums[i], nums[j], target});
          while (j+1<n && nums[j]==nums[j+1]) ++j;  // skip dulpicate
        }
        m[nums[j]] = j;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
