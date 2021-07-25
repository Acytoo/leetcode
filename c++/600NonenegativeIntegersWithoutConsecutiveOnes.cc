#include <iostream>
#include <sstream>
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
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// fibonacci-like, https://blog.csdn.net/magicbean2/article/details/78968556
class Solution {
 public:
  int findIntegers(int n) {
    int fib[32];
    // memset(fib, 0, sizeof fib);
    fib[0] = 1; fib[1] = 2;
    for (int i = 2; i < 32; ++i)
      fib[i] = fib[i - 1] + fib[i - 2];
    int res = 0, k = 30;
    bool pre_one = false;
    while (k >= 0) {
      if (n & (1 << k)) {
        res += fib[k];
        if (pre_one) return res;
        pre_one =true;
      } else {
        pre_one = false;
      }
      --k;
    }
    return res + 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
