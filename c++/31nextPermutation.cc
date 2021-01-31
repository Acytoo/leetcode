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
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i != -1)
      for (int j = nums.size() - 1; j > i; --j)
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          break;
        }
    reverse(nums.begin() + i + 1, nums.end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
