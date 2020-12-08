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
// From huahua
class Solution {
 public:
  int concatenatedBinary(int n) {
    constexpr int kMod = 1e9 + 7;
    long res = 0;
    for (int i = 1, len = 0; i <= n; ++i) {
      if ((i & (i - 1)) == 0) ++len;
      res = ((res << len) % kMod + i) % kMod;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
