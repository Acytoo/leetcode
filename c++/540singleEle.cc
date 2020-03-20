#include <iostream>
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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while (l < r) {
      int m = (l+r) >> 1, n = m ^ 1;
      if (nums[m] == nums[n])
        l = m + 1;
      else
        r = m;
    }
    return nums[l];
  }
};

int main() {
  Solution s;
  vector<int> a = {1,1,2,3,3};
  cout << s.singleNonDuplicate(a) << endl;
  return 0;
}
