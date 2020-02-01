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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    nums_ = nums;
  }

  int sumRange(int i, int j) {
    int res = 0;
    while (i <= j)
      res += nums_[i++];
    return res;
  }
 private:
  vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {
  Solution s;
  
  return 0;
}
