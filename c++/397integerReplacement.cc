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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int integerReplacement(int n) {
    // int res = 0;
    if (n == 1)
      return 0;
    if (n & 1) {
      long nn = static_cast<long> (n);
      return 2 + min(integerReplacement((nn+1)>>1), integerReplacement((nn-1)>>1));
    } else {
      return 1 + integerReplacement(n>>1);
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
