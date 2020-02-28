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
// -1000 ≤ nums[i] ≤ 1000
// nums[i] ≠ 0
// 1 ≤ nums.length ≤ 5000
class Solution {
 public:
  bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return false;
    for (int i=0; i<n; ++i)
      if (nums[i] < 0) {
        if (backward_check(nums, i))
          return true;
      } else {
        if (forward_check(nums, i))
          return true;
      }
    return false;
  }
 private:
  bool forward_check(vector<int>& nums, int start_idx) const {
    int n = nums.size();
    vector<bool> visited(n, false);
    int i = start_idx;
    while (!visited[i]) {
      visited[i] = true;
      if (nums[i] < 0)
        return false;
      i += nums[i];
      while (n <= i)
        i -= n;
    }
    start_idx = i;
    int next_idx = i + nums[i];
    while (n <= next_idx)
      next_idx -= n;
    return next_idx != start_idx;
  }
  bool backward_check(vector<int>& nums, int start_idx) const {
    int n = nums.size();
    vector<bool> visited(n, false);
    int i = start_idx;
    while (!visited[i]) {
      visited[i] = true;
      if (0 < nums[i])
        return false;
      i += nums[i];
      while (i < 0)
        i += n;
    }
    start_idx = i;
    int next_idx = i + nums[i];
    while (next_idx < 0)
      next_idx += n;
    return next_idx != start_idx;
  }
};

int main() {
  Solution s;
  vector<int> a = {2,-1,1,2,2};
  // a = {-1,2};
  // a = {-2,1,-1,-2,-2};
  // a = {2, -1};
  // a = {-1,-2,-3,-4,-5};
  a = {-2, -3, -9};
  cout << s.circularArrayLoop(a) << endl;
  return 0;
}
