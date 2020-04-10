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
// target will be a non-zero integer in the range [-10^9, 10^9]
class Solution {
 public:
  int reachNumber(int target) {
    // if (target == 0) return 0;
    if (target < 0) target = -target;  // Mirror
    int res = 0, sum = 0;
    while (sum < target || ((sum-target) & 1))
      sum += ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
