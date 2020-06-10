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
  int superPow(int a, vector<int>& b) {
    if (b.empty() || a == 1 || a == 0) return a;
    constexpr int kMod = 1337;
    a %= kMod;  // a = INT_MAX
    function<int(int, int)> modPow =
        [] (const int a, int b) {
          if (b < 0) return -1;
          if (b == 0) return 1;
          int res = a % kMod;
          while (--b)
            res = res * a % kMod;
          return res;
        };
    int res = modPow(a, b[0]);
    for (int i = 1, stop = b.size(); i < stop; ++i)
      res = modPow(res, 10) * modPow(a, b[i]) % kMod;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
