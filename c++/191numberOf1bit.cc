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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    // built in function from GCC
    // return __builtin_popcount(n);
    // or
    int res = 0;
    while (n) {
      res += (n&1);
      n >>= 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.hammingWeight(3) << endl;
  return 0;
}
