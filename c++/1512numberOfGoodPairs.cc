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

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // 4 ms O(n)
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int a[101];
    memset(a, 0, sizeof(a));
    for (const int num: nums) ++a[num];
    int res = 0;
    for (int i = 1; i < 101; ++i)
      if (a[i] > 1) res += ((a[i] * (a[i] - 1)) >> 1);
    return res;
  }
};

class Solution1 {  // 4 ms O(n^2)
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int res = 0;
    for (int i = 0, n = nums.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (nums[i] ==  nums[j]) ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
