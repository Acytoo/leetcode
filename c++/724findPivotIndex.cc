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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    const int n = nums.size();
    if (n == 0) return -1;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int left = 0;
    for (int i = 0; i < n; ++i)
      if (left == sum - nums[i] - left)
        return i;
      else
        left += nums[i];
    return -1;
  }
};

class Solution1 {
 public:
  int pivotIndex(vector<int>& nums) {
    const int n = nums.size();
    if (n == 0) return -1;
    vector<int> left (n), right (n);
    left[0] = nums[0]; right.back() = nums.back();
    for (int i = 0, stop = n - 1; i < stop; ) left[i] = left[i] + nums[++i];
    for (int j = n - 1; j > 0; ) right[j] = right[j] + nums[--j];

    for (int i = 0; i < n; ++i)
      if (left[i] == right[i]) return i;
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
