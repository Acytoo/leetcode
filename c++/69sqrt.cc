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


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // binary search
 public:
  int mySqrt(int x) {
    long l = 1, r = static_cast<long>(x) + 1;
    while (l < r) {
      const long m = l + (r - l) / 2;
      if (m * m <= x)
        l = m + 1;
      else
        r = m;
    }
    return l - 1;
  }
};

class Solution_OLD {
 public:
  int mySqrt(int x) {
    long l = 1, r = static_cast<long> (x) + 1;
    while (l < r) {
      long m = (l+r) >> 1;
      if (m*m <= x) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l - 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
