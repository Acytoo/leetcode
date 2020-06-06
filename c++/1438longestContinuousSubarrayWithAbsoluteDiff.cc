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
  int longestSubarray(vector<int>& nums, int limit) {
    int res = 0;
    deque<int> max_q, min_q;
    for (int l = 0, r = 0, stop = nums.size(); r < stop; ++r) {
      while (!min_q.empty() && nums[r] < min_q.back()) min_q.pop_back();
      while (!max_q.empty() && nums[r] > max_q.back()) max_q.pop_back();
      min_q.push_back(nums[r]);
      max_q.push_back(nums[r]);
      while (max_q.front() - min_q.front() > limit) {
        if (min_q.front() == nums[l]) min_q.pop_front();
        if (max_q.front() == nums[l]) max_q.pop_front();
        ++l;
      }
      res = max(res, r - l + 1);
    }
    return res;
  }
};

class Solution1 {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int res = 0;
    multiset<int> s;
    for (int l = 0, r = 0, stop = nums.size(); r < stop; ++r) {
      s.insert(nums[r]);
      while (*s.rbegin() - *s.begin() > limit)
        s.erase(s.equal_range(nums[l++]).first);  // erase one element, not all elements equal to nums[l]
      res = max(res, r - l + 1);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
