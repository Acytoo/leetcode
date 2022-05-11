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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int third = INT_MIN;
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < third) return true;
      while (!st.empty() && nums[i] > st.top()) {
        third = st.top(); st.pop();
      }
      st.push(nums[i]);
    }
    return false;
  }
};
// 1  3  2
class Solution_OLD_TLE {
 public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size()-1, i = 0, j = 0, k = 0;
    while (i < n) {
      while (i < n && nums[i] >= nums[i+1])
        ++i;
      j = i + 1;
      while (j < n && nums[j] <= nums[j+1])
        ++j;
      k = j + 1;
      while (k <= n) {
        if (nums[k] > nums[i] && nums[k] < nums[j])
          return true;
        ++k;
      }
      i = j + 1;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
