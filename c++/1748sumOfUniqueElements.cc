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
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100
class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    int num[101];
    memset(num, 0, sizeof num);
    int res = 0;
    for (const int a: nums)
      if (++num[a] == 1)
        res += a;
      else if (num[a] == 2)
        res -= a;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
