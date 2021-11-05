#include <iostream>
#include <cmath>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int arrangeCoins(long n) {  // long n, not int
    return static_cast<int>(sqrt((n << 1) + 0.25) - 0.5);
  }
};

class Solution1 {
 public:
  int arrangeCoins(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      ++res;
      n -= i;
    }
    return res;
  }
};

class Solution_FUN {
 public:
  int arrangeCoins(int n) {
    int i = 1;
    for (; i <= n; n -= i++) { }
    return i;
  }
};

/*
  matn solution:
  1 : 1
  2 : 1
  3 : 2
  4 : 2
  5 : 2
  6 : 3
  .
  .
  9 : 3
  10 : 4
  .
  .
  .
  15 : 5
  16 : 5
  .
  .
  21 : 6
  ((1 + floor_res) * floor_res ) / 2 = n
  0.5 x^2 + 0.5x - y = 0

  ax^2 + bx + c = 0 --> x = (-b + sqrt(b^2 - 4ac))/2a
 */
class Solution_OLD {
public:
  int arrangeCoins(int n) {
    return floor(((sqrt(1+8.0*n)-1) / 2));
  }
};

int main() {

  Solution s;
  cout << s.arrangeCoins(1804289383) << endl;
  return 0;
}
