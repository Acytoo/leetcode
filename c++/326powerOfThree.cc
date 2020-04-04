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

class Solution {
 public:
  // No loop or recursion
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
};

class Solution1 {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    // int all[20] = {0};
    // for (int i=0; i != 20; ++i) all[i] = pow(3, i);
    int all[20] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
    int l = 0, r = 19;
    while (l <= r) {
      int m = (l+r) >> 1;
      if (n == all[m]) return true;

      if (n < all[m])
        r = m - 1;
      else
        l = m + 1;
    }
    return false;
  }
};

int main() {
  Solution s;
  cout << s.isPowerOfThree(45) << endl;
  return 0;
}
