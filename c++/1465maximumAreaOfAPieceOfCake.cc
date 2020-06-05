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
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    constexpr int kMod = 1e9 + 7;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int max_row = h - horizontalCuts.back(),
        max_col = w - verticalCuts.back();
    for (int i = horizontalCuts.size() - 1; i > 0; )
      max_row = max(max_row, horizontalCuts[i] - horizontalCuts[--i]);
    for (int i = verticalCuts.size() - 1; i > 0; )
      max_col = max(max_col, verticalCuts[i] - verticalCuts[--i]);
    max_row = max(max_row, horizontalCuts.front() - 0);
    max_col = max(max_col, verticalCuts.front() - 0);
    return  static_cast<long>(max_row) * max_col % kMod;
  }
};

int main() {
  Solution s;
  
  return 0;
}
