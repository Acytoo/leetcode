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
class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // bitset<(1 << 20)> mem;
    if (desiredTotal <= 0) return true;
    const int sum = (1 + maxChoosableInteger) * maxChoosableInteger >> 1;
    if (sum < desiredTotal) return false;  // both lose
    vector<char> mem (1 << maxChoosableInteger);
    function<bool(int, int, int)> helper =
        [&] (int m, int d, int state) {
          if (d <= 0) return false;
          if (mem[state]) return mem[state] == 1;
          for (int i = 0; i < m; ++i) {
            if (state & (1 << i)) continue;  // number i is used before
            if (!helper(m, d - (i + 1), state | (1 << i))) {  // one must win
              mem[state] = 1;
              return true;
            }
          }
          mem[state] = -1;
          return false;
        };
    return helper(maxChoosableInteger, desiredTotal, 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
