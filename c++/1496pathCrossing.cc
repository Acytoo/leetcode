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
  bool isPathCrossing(string path) {
    unordered_map<int, unordered_set<int>>  m;// x_coordinate, set of y_coordinates
    m[0].insert(0);
    int x = 0, y = 0;
    for (const char c: path) {
      switch (c) {
        case 'N': ++y; break;
        case 'S': --y; break;
        case 'E': ++x; break;
        case 'W': --x; break;
      }
      if (m.count(x) && m[x].count(y)) return true;
      m[x].insert(y);
    }
    return false;
  }
};

int main() {
  Solution s;
  cout << s.isPathCrossing("NESWW") << endl;
  return 0;
}
