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
  int specialArray(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    for (int i = 0, n = nums.size(); i < n; ) {
      if (nums[i] >= ++i)
        if (i == n || nums[i] < i) return i;
    }
    return -1;
  }
};

class Solution1 {
 public:
  int specialArray(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    for (int i = 0, n = nums.size(); i < n; ++i) {
      if (nums[i] >= i + 1)
        if (i + 1 == n || nums[i + 1] < i + 1) return i + 1;
    }
    return -1;
  }
};
int main() {
  Solution s;
  
  return 0;
}
