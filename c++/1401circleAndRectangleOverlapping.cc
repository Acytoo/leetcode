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
  bool checkOverlap(int radius, int x_center, int y_center,
                    int x1, int y1, int x2, int y2) {
    const int dx = x_center - max(x1, min(x2, x_center)),
              dy = y_center - max(y1, min(y2, y_center));
    return dx * dx + dy * dy <= radius * radius;
  }
};

int main() {
  Solution s;
  
  return 0;
}
