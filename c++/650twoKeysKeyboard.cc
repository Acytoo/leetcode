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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minSteps(int n) {
    if (n == 1) return 0;
    if (n <= 5) return n;
    int res = n;
    for (int i=2; i<n; ++i)
      if (n % i == 0)
        res = min(res, minSteps(n / i) + i);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
