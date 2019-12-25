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
#include <time.h>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 水塘采样
class Solution {
 public:
  Solution(vector<int>& nums) {
    nums_ = nums;
  }

  int pick(int target) {
    int n = 0, res = -1;
    // srand(time(0)); // can't use srand()
    // very large array
    for (long unsigned int i=0, stop=nums_.size(); i<stop; ++i) {
      if (target != nums_[i]) continue;
      if (n == 0) {
        res = i;
        ++n;
      } else {
        ++n;
        if (rand() % n == 0)  // rang() ...
          res = i;
      }
    }
    return res;
  }
 private:
  vector<int> nums_;
};

int main() {
  vector<int> a = {1,2,2,3,3,4};
  Solution * s = new Solution(a);
  int res = s->pick(3);
  cout << res << endl;
  delete(s);
  return 0;
}
