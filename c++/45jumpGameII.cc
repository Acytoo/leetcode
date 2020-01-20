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

using namespace std;

// Must can reach the end
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int jump(vector<int> & nums) {
    int res = 0, last = 0, cur = nums[0], n = nums.size()-1;
    for (int i=0; i<=n; ++i) {
      if (last < i) {
        last = cur;
        ++res;
      }
      cur = max(cur, i+nums[i]);
    }
    return res;
  }
};

class Solution1 {
 public:
  int jump(vector<int>& nums) {
    int res = 0, cur = 0, i = 0, n = nums.size()-1;  // n: last index
    while (cur < n) {
      ++res;
      int pre = cur;
      for (; i<=pre; ++i) {
        cur = max(cur, i+nums[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;

}
