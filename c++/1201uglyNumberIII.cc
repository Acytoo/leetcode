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
 public:
  int nthUglyNumber(int n, long a, long b, long c) {
    long l = 1;
    long r = INT_MAX;
    long ab = std::lcm(a, b);
    long ac = std::lcm(a, c);
    long bc = std::lcm(b, c);
    long abc = std::lcm(a, bc);
    while (l < r) {
      long m = (l + r) / 2;
      long k = m/a + m/b + m/c - m/ab - m/ac - m/bc + m/abc;
      if (n <= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

int main() {
  Solution s;
  int n = 5, a = 2, b = 11, c = 13;
  cout << s.nthUglyNumber(n, a, b, c) << endl;
  return 0;
}
