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

// 1 <= nums.length <= 10^4
// 1 <= nums[i] <= 10^5
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int res = 0;
    for (const int num: nums) {
      if (num <= 4) continue;
      int root = sqrt(num);
      if (root * root == num) continue;
      int count = 2;  // 1 and itself
      int sum = 1 + num;
      for (int i = 2; i <= root; ++i)
        if (num % i == 0) {
          count += 2;
          sum += i + num / i;
        }
      if (count == 4) res += sum;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
