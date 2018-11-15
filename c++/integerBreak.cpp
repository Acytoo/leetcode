#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
  int integerBreak(int n) {
    if (n < 4)
      return n-1;
    int res=1;
    while (n > 4) {
      res *= 3;
      n -= 3;
    }
    return res*n;
  }
};

int main() {

  // 7 = 3+4; 11 = 3+8;
  // all other nums bigger than 3 can be got from 2 and 3 , 28 = 15+13, 14+14, 16+12,...,  
  return 0;
}
