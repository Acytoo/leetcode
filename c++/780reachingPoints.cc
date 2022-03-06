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
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx >= sx && ty >= sy) {
      if (tx > ty) {
        if (ty == sy) return (tx - sx) % ty == 0;
        tx %= ty;
      } else {
        if (tx == sx) return (ty - sy) % tx == 0;
        ty %= tx;
      }
    }
    return tx == sx && ty == sy;
  }
};

int main() {
  Solution s;
  
  return 0;
}
