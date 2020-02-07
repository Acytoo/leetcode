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
// Faster solution from leetcode
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t lut[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    uint32_t result = 0;
    for (int i = 0; i < 8; ++i) {
      result <<= 4;
      result |= lut[n & 0xf];
      n >>= 4;
    }
    return result;
  }
};

class Solution1 {
 public:
  uint32_t reverseBits(uint32_t n) {
    int res = 0;
    for (int i=0; i<32; ++i) {
      res <<= 1;
      res = res | n & 1;
      n >>= 1;
    }
    return res;
  }
};


int main() {
  Solution s;
  int a = 123;
  cout << s.reverseBits(a) << endl;
  return 0;
}
