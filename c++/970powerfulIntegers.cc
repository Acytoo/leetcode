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
// 1 <= x <= 100
// 1 <= y <= 100
// 0 <= bound <= 10^6
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> s;
    for (int xx=1; xx<=bound; xx*=x) {
      for (int yy=1; yy<=bound; yy*=y) {
        int sum = xx + yy;
        if (sum <= bound)
          s.insert(xx+yy);
        else
          break;
        if (y == 1) break;
      }
      if (x == 1) break;
    }
    return vector<int> (s.begin(), s.end());
  }
};

int main() {
  Solution s;

  return 0;
}
