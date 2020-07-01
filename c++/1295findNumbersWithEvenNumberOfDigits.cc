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
// 1 <= nums.length <= 500
// 1 <= nums[i] <= 10^5
class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (int num: nums) {
      int count = 0;
      while (num) {
        ++count;
        num /= 10;
      }
      res += ((count & 1) == 0);
    }
    return res;
  }
};

class Solution1 {
 public:
  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (const int num: nums)
      if ((9 < num && num < 100) || (999 < num && num < 10000) || num = 1e5) ++res;
    return res;
  }
};

class Solution1 {
 public:
  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (const int num: nums)
      if (num < 10)  // 1 - 9
        continue;
      else if (num < 100)  // 10 - 99
        ++res;
      else if (num < 1000)  // 100 - 999
        continue;
      else if (num < 10000)  // 1000 - 9999
        ++res;
      else if (num < 100000)  // 10000 - 99999
        continue;
      else  // 100000
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
