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
class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int res = INT_MAX;
    for (int i = 0, n = nums.size(); i < n; ++i)
      if (nums[i] == target)
        res = min(res, abs(i - start));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
