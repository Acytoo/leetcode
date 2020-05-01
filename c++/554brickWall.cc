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
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> m;
    int max_n = 0;
    for (const auto &bricks: wall) {
      int len = 0;
      for (int i=0, stop=bricks.size()-1; i<stop; ++i) {
        len += bricks[i];
        max_n = max(max_n, ++m[len]);
      }
    }
    return wall.size() - max_n;
  }
};

int main() {
  Solution s;
  
  return 0;
}
