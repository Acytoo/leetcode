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
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int res = 0;
    while (z != 0) {
      res += (z & 1);
      z >>= 1;
    }
    return res;
  }
};

class Solution_builtin {
 public:
  int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
  }
};

class Solution2 {
 public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int res = 0;
    while (z != 0) {
      z &= (z-1);
      res++;
    }
    return res;
  }
};

class Solution1 {
 public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int res = 0;
    while (z > 0) {
      res += (z&1);
      z >>= 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
