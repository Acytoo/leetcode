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
  int countBalls(int lowLimit, int highLimit) {
    vector<int> boxes(55);
    int res = 0;
    for (int i = lowLimit; i <= highLimit; ++i) {
      int box = 0, num = i;
      while (num > 0) {
        box += num % 10;
        num /= 10;
      }
      res = max(res, ++boxes[box]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
