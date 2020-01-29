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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    if (nums.size() == 1)
      return 0;
    int i1 = nums[0] < nums[1]? 1: 0, i2 = 1-i1;
    // nums[i1] >= nums[i2]
    for (int i=2, stop=nums.size(); i<stop; ++i) {
      if (nums[i2] < nums[i]) {
        if (nums[i1] < nums[i]) {
          i2 = i1;
          i1 = i;
        } else {
          i2 = i;
        }
      }
    }
    if (nums[i2] <= (nums[i1]>>1))
      return i1;
    return -1;
  }
};

int main() {
  Solution s;
  vector<int>a {0, 1};
  cout << s.dominantIndex(a) << endl;
  return 0;
}
