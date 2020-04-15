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
// 3 points not in a straight line, then one boomerang
class Solution {
 public:
  bool isBoomerang(vector<vector<int>>& points) {
    int dx1 = points[1][0] - points[0][0],
        dy1 = points[1][1] - points[0][1],
        dx2 = points[2][0] - points[1][0],
        dy2 = points[2][1] - points[1][1];
    return dx1*dy2 != dx2*dy1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
