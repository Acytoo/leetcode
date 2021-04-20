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

// 1 <= nums.length <= 5000
// 1 <= nums[i] <= 104

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int res = 0, last = 0;
    for (const int a : nums)
      if (a > last)
        last = a;
      else
        res += ++last - a;
    return res;
  }
};

class Solution1 {
 public:
  int minOperations(vector<int>& nums) {
    int res = 0, last = 0;
    for (const int a : nums)
      if (a > last) {
        last = a;
      } else {
        res += last + 1 - a;
        last = last + 1;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
