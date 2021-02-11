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

// 3,4,5,1,2,3
// 3,4,5,1,2
// 2,1,3,4

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool check(vector<int>& nums) {
    int t = 0;
    for (int i = 0, n = nums.size() - 1; i < n; )
      if (nums[i] > nums[++i])
        ++t;
    if (t == 0) return true;
    if (t > 1) return false;
    return nums.front() >= nums.back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
