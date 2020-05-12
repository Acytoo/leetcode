#include <iostream>
#include <climits>
using namespace std;

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (divisor == 1)
      return dividend;
    if (divisor == -1)
      if (dividend == INT_MIN)
        return INT_MAX;
      else
        return -1 * dividend;
    
    bool positive = (dividend ^ divisor) > -1 ? true : false;
    long dend = labs(dividend);
    long sor = labs(divisor);
    if (dend < sor)
      return 0;
    int res = 0;
    while (dend - (sor << 14)>= 0) {
      dend -= (sor << 14);
      res += 16384;
    }
    while (dend - (sor << 13)>= 0) {
      dend -= (sor << 13);
      res += 8192;
    }
    while (dend - (sor << 12)>= 0) {
      dend -= (sor << 12);
      res += 4096;
    }
    while (dend - (sor << 11)>= 0) {
      dend -= (sor << 11);
      res += 2048;
    }
    while (dend - (sor << 10)>= 0) {
      dend -= (sor << 10);
      res += 1024;
    }
    while (dend - (sor << 9)>= 0) {
      dend -= (sor << 9);
      res += 512;
    }
    while (dend - (sor << 8)>= 0) {
      dend -= (sor << 8);
      res += 256;
    }
    while (dend - (sor << 7)>= 0) {
      dend -= (sor << 7);
      res += 128;
    }
    while (dend - (sor << 6)>= 0) {
      dend -= (sor << 6);
      res += 64;
    }
    while (dend - (sor << 5)>= 0) {
      dend -= (sor << 5);
      res += 32;
    }
    while (dend - (sor << 4)>= 0) {
      dend -= (sor << 4);
      res += 16;
    }
    while (dend - (sor << 3)>= 0) {
      dend -= (sor << 3);
      res += 8;
    }
    
    while (dend - (sor << 2)>= 0) {
      dend -= (sor << 2);
      res += 4;
    }
    while (dend - (sor << 1)>= 0) {
      dend -= (sor << 1);
      res += 2;
    }
    while (dend >= sor) {
      dend -= sor;
      res += 1;
    }
    
    return positive ? res : -1*res;
  }
};

class Solution1 {
 public:
  int divide(int dividend, int divisor) {
    if (divisor == 1)
      return dividend;
    if (divisor == -1)
      if (dividend == INT_MIN)
        return INT_MAX;
      else
        return -1 * dividend;
    
    bool positive = (dividend ^ divisor) > -1 ? true : false;
    long dend = labs(dividend);
    long sor = labs(divisor);
    if (dend < sor)
      return 0;
    int res = 0;
    while (dend - (sor << 2)>= 0) {
      dend -= (sor << 2);
      res += 4;
    }
    while (dend - (sor << 1)>= 0) {
      dend -= (sor << 1);
      res += 2;
    }
    while (dend >= sor) {
      dend -= sor;
      res += 1;
    }
    return positive ? res : -1*res;
  }
};

int main() {
  Solution s;
  int a = 10, b = -3;
  cout << s.divide(INT_MIN, 31) << endl;
  return 0;
}
