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
  int numberOfMatches(int n) {
    int res = 0;
    while (n > 1) {
      if (n & 1) {
        n >>= 1;
        res += n;
        ++n;
      } else {
        n >>= 1;
        res += n;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
