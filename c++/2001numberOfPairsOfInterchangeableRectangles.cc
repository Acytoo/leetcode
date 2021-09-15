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
// n == rectangles.length
// 1 <= n <= 105
// rectangles[i].length == 2
// 1 <= widthi, heighti <= 105
class Solution {  // shit code but passed
 public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, int> m;
    for (const auto &rec : rectangles)
      m[static_cast<double>(rec[0])/rec[1]]++;
    int res = 0;
    for (auto &[k, v] : m)
      res += v * (v - 1) / 2;
    return res;
  }
};

// one test cast is all same rectangle, with difficult-to-divid width and height, a thouand of [32768,65536]

int main() {
  Solution s;
  
  return 0;
}
