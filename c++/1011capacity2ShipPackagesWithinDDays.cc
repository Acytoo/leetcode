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
// From Huahua
class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int D) {
    int l = 0, r = 1;
    for (const int w: weights) {
      if (l < w) l = w;
      r += w;
    }

    while (l < r) {
      int m = (l + r) >> 1;
      int d = 1, t = 0;
      for (const int w: weights)
        if ((t+=w) > m) {
          t = w;
          ++d;
        }
      d > D? l = m + 1: r = m;
    }
    return l;
  }
};

int main() {
  Solution s;
  
  return 0;
}
