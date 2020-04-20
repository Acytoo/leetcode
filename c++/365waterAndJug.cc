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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// z = m*x + n*y, Bezout's identity
// Note, you only have two jugs, not three
class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    return z == 0 || ((x + y >= z) && (z % gcd(x, y) == 0));
  }
};

int main() {
  Solution s;
  cout << s.canMeasureWater(1, 1, 12) << endl;
  return 0;
}
