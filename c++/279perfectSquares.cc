#include <iostream>
#include <cmath>
using namespace std;


static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
// Math: Lagrange's four-square theorem
class Solution {
 public:
  int numSquares(int n) {
    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) return 4;
    for (int a = 0, a2 = a * a; a2 <= n; ++a, a2 = a * a) {
      int b = sqrt(n - a2);
      if (a2 + b * b == n)
        return !!a + !!b;
    }
    return 3;
  }
};

// DP dp[i] = min(dp[i - j] + 1), j is some square
class Solution_DP {
 public:
  int numSquares(int n) {
    // if (pow(static_cast<int>(sqrt(n)), 2) == n) return 1;
    vector<int> dp (n + 1, INT_MAX >> 1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1, j2 = j * j; j2 <= i; ++j, j2 = j * j)
        dp[i] = min(dp[i], dp[i - j2] + 1);
    return dp[n];
  }
};



//Since the result is in [1,2,3,4]
/*
  1: 1, 4, 9, 16, ....
  2: 2, 5, 8, 10, 13, 17, 18, 20 ....
  3: 3, 6, 11, 12, 14, 19, 21, 22 ....
  4: 7, 15, 23, ....
  near n^1 (+1)(1 = 1 ^ 2) or sum of two ^2: 2
  8*n + 7 : 4
  n^2 : 1
  rest : 3
*/
class Solution_OLD {
 public:
  int numSquares(int n) {
    if (pow(floor(sqrt(n)), 2) == n) return 1;

    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) return 4;

    for (int i = 1, m = 0; i * i <= n; ++i) {
      m = n - i * i;
      if (pow(floor(sqrt(m)), 2) == m) return 2;
    }
    return 3;
  }
};


//DP solution
class Solution1_OLD {
 public:
  int numSquares(int n) {
    int a[n + 1] = {0};
    if (pow(floor(sqrt(n)), 2) == n)
      return 1;

    for (int i = 1; i <= n; ++i) {
      a[i] = 999;
      int max = floor(sqrt(i));
      while (max > 0) {
        a[i] = min(a[i - max * max] + 1, a[i]);
        --max;
      }
    }
    return a[n];
  }
};

int main() {
  int n;
  Solution s;
  while (cin >> n)
    cout << s.numSquares(n) << endl;
  return 0;
}
