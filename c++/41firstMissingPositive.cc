#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution1 {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0, n = nums.size(); i < n; ++i)
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0, n = nums.size(); i < n; )
      if (nums[i] != ++i) return i;
    return nums.size() + 1;
  }
};

int main() {
  Solution s;
  vector<int> a = {-1, 4, 2, 1, 9, 10};
  cout << s.firstMissingPositive(a) << endl;
  return 0;
}
