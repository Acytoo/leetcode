#include <iostream>
#include <cmath>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
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
  x = sqrt((4ac-b^2)/2a) x in range(Z)
  sqrt(2y - 0.25)
 */
class Solution {
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
