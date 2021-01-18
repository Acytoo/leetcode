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
// 1 <= rectangles.length <= 1000
// rectangles[i].length == 2
// 1 <= li, wi <= 109
// li != wi
class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    map<int, int> m;
    for (const auto &r: rectangles)
      ++m[min(r[0], r[1])];
    return (--m.end())->second;
  }
};

int main() {
  Solution s;
  
  return 0;
}
