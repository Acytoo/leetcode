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
  int minEatingSpeed(vector<int>& piles, int H) {
    if (piles.size() == H) return *max_element(piles.begin(), piles.end());
    int l = 1, r = *max_element(piles.begin(), piles.end()) + 1;
    while (l < r) {
      int m = (l + r) >> 1, h = 0;
      for (const int pile: piles)
        h += (pile + m - 1) / m;
      if (h <= H)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

int main() {
  Solution s;
  
  return 0;
}
