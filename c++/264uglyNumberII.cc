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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int nthUglyNumber(int n) {
    static vector<int> ugly_nums{1};
    static int i2 = 0;
    static int i3 = 0;
    static int i5 = 0;
    while (ugly_nums.size() < n) {
      const int next2 = ugly_nums[i2] * 2;
      const int next3 = ugly_nums[i3] * 3;
      const int next5 = ugly_nums[i5] * 5;
      const int next = min(next2, min(next3, next5));
      if (next == next2) ++i2;
      if (next == next3) ++i3;
      if (next == next5) ++i5;
      ugly_nums.push_back(next);
    }
    return ugly_nums.back();
  }
};

int main() {
  Solution s;
  cout << s.nthUglyNumber(1) << endl;
  return 0;
}
