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
  int countPoints(string rings) {
    int rod[10] = {0};
    for (int i = 0, n = rings.size(); i < n; ++i)
      if (rings[i] == 'R') {
        rod[rings[++i] - '0'] |= (0b001);
      } else if (rings[i] == 'G') {
        rod[rings[++i] - '0'] |= (0b010);
      } else {
        rod[rings[++i] - '0'] |= (0b100);
      }
    int res = 0;
    for (int i = 0; i < 10; ++i)
      if (rod[i] == 0b111)
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
