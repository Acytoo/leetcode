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
class Solution {  // 0ms
 public:
  int rangeBitwiseAnd(int m, int n) {
    while(n > m) n = n & (n-1);
    return n;
  }
};

class Solution2 {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int count = 0;
    while (m && m != n) {
      m >>= 1;
      n >>= 1;
      ++count;
    }
    return m << count;
  }
};

class Solution1 {  // 420ms
 public:
  int rangeBitwiseAnd(int m, int n) {
    long res = static_cast<long> (m);
    for (long i=res+1; i<=n; ++i)
      if (res == 0)
        return 0;
      else
        res &= i;
    return static_cast<int>(res);
  }
};

int main() {
  Solution s;
  cout << s.rangeBitwiseAnd(2147483646,
                            2147483647) << endl;
  return 0;
}
