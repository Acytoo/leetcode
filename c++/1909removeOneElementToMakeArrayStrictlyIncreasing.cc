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
  bool canBeIncreasing(vector<int>& nums) {
    int prev = INT_MIN;
    bool seen = false;
    for (int i = 0, stop = nums.size(); i < stop; ++i) {
      if (prev < nums[i]) {
        prev = nums[i];
      } else {
        if (seen) return false;
        seen = true;
        if (i == 1 || nums[i - 2] < nums[i]) prev = nums[i];
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
