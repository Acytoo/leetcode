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
  int binaryGap(int n) {
    int res = 0;
    int curMax = 0;
    bool start = false;
    while (n > 0) {
      if (start)
        ++curMax;
      if (n & 1 == 1) {
        start = true;
        res = max(res, curMax);
        curMax = 0;
      }
      n >>= 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.binaryGap(6) << endl;
  return 0;
}
