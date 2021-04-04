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
// From grandyang
class Solution {
 public:
  int countDigitOne(int n) {
    long res = 0, a = 1, b = 1;
    while (n > 0) {
      res += (n + 8) / 10 * a + (n % 10 == 1) * b;
      b += n % 10 * a;
      a *= 10;
      n /= 10;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
