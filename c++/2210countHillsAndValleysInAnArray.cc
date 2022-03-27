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
  int countHillValley(vector<int>& nums) {
    vector<int> arr;
    arr.emplace_back(nums.front());
    for (auto a : nums) if (a != arr.back()) arr.emplace_back(a);
    int res = 0;
    for (int i = 1, stop = arr.size() - 1; i < stop; ++i)
      if ((arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) ||
          arr[i - 1] > arr[i] && arr[i + 1] > arr[i])
        ++res;
    return res;
  }
};

class Solution1 {
 public:
  int countHillValley(vector<int>& nums) {
    int res = 0;
    for (int i = 1, stop = nums.size() - 1; i < stop; ) {
      int left = i - 1, right = i + 1;
      while (nums[left] == nums[i] && left > 0) --left;
      while (nums[right] == nums[i] && right < stop) ++right;
      if (nums[left] < nums[i] && nums[right] < nums[i]) ++res;
      else if (nums[left] > nums[i] && nums[right] > nums[i]) ++res;
      i = right;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
