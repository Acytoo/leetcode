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
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isRobotBounded(string instructions) {
    int x = 0, y = 0, d = 0;  // (x, y) for position and d for direction {0, 1, 2, 3}
    for (const char c: instructions)
      if (c == 'G') {
        switch (d) {
          case 0: ++x; break;
          case 1: ++y; break;
          case 2: --x; break;
          case 3: --y; break;
        }
      } else if (c == 'L') {
        --d;
        if (d == -1) d = 3;
      } else {
        ++d;
        if (d == 4) d = 0;
      }

    return (x == 0 && y == 0) || d != 0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
