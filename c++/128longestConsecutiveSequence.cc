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
#include <unordered_set>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> h(nums.begin(), nums.end());
    int ans = 0;
    for (int num : nums)
      if (!h.count(num - 1)) {
        int l = 0;
        while (h.count(num++)) ++l;
        ans = max(ans, l);
      }
    return ans;
  }
};

// Sort first
class Solution_SLOW {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int res = 1, cur_streak = 1;
    for (int i=1, stop=nums.size(); i < stop; ++i) {
      if (nums[i] != nums[i-1]) {
        if (nums[i] == nums[i-1] + 1) {
          ++ cur_streak;
        } else {
          res = max(res, cur_streak);
          cur_streak = 1;
        }
      }
    }
    return max(res, cur_streak);
  }
};


// To nake it faster, we can use map to sort and index the num
// Seems much faster
class Solution2 {
public:
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_set<int> num_set(nums.begin(), nums.end());
    for (int num: nums) {
      if (num_set.find(num-1) == num_set.end()) { // No need to continue if we can find its previous num
        int cur_num = num;
        int cur_streak = 1;
        while (num_set.find(cur_num+1) != num_set.end()) {
          ++cur_num;
          ++cur_streak;
        }
        res = max(res, cur_streak);
      }
    }
    return res;
  }
};


// slow but easy to understand
// Time limit exceeded
class Solution1 {
public:
  template <typename T>
  bool in_array(vector<T>& arr, T one) {
    for (auto i : arr)
      if (i == one)
        return true;
    return false;
  }
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    for (int num: nums) {
      int cur_num = num;
      int cur_streak = 1;

      while (in_array(nums, cur_num+1)) {
        ++cur_num;
        ++cur_streak;
      }
      res = max(res, cur_streak);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {2,4,3,6,78};
  cout << s.longestConsecutive(a) << endl;
  return 0;
}
