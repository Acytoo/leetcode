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

  double myPow(double x, int n) {
    unsigned long exp = n;
    double res = 1.0;
    if (n < 0) {
      exp = -n;
      x = 1 / x;
    }
    while (exp) {
      if (exp & 1) {
        res *= x;
      }
      x *= x;
      exp >>= 1;
    }
    return res;
  }

  // 快速幂算法
  double myPow2(double x, int n) {

    unsigned long absN = labs(n);
    double res = 1;
    double base = x;
    while (absN != 0) {
        if (absN & 1)
          res *= base;
        base *= base;
        absN >>= 1;
      }
    return n > 0 ? res : 1/res;
  }

  // Easy but slow
  double myPow1(double x, int n) {
    if (n < 0)
      return 1 / myPow(x, -n);
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    return x * myPow(x, --n);
  }
};

int main() {
  Solution s;
  cout << s.myPow(2.0, 2) << endl;
  return 0;
}
