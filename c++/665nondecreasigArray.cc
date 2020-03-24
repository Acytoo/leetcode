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
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size() - 1;
    if (n == 0)
      return true;
    bool nond = false;
    for (int i=0; i<n;)
      if (nums[i] > nums[++i]) {
        if (nond)
          return false;
        int tmp_l = i>1? nums[i-2]: INT_MIN;
        int tmp_r = i<n? nums[i+1]: INT_MAX;
        if (nums[i] < tmp_l && tmp_r < nums[i-1])
          return false;
        nond = true;
      }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> a = {0,8,1,2};
  cout << s.checkPossibility(a) << endl;
  return 0;
}
