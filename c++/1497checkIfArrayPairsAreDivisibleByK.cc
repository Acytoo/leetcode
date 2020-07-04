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
  bool canArrange(vector<int>& arr, int k) {
    vector<int> rems (k);
    for (const int a: arr) {
      int rem = a % k;
      rem = rem >= 0? rem: rem + k;
      ++rems[rem];
    }
    if ((rems[0] & 1) != 0) return false;
    if (k & 1) {  // k is odd, eg: k = 5, then possible remainder: 0, 1, 2, 3, 4
      for (int i = 1, stop = k >> 1; i <= stop; ++i)
        if (rems[i] != rems[k - i])
          return false;
    } else {  // k is even
      if ((rems[k >> 1] & 1) != 0) return false;
      for (int i = 1, stop = k >> 1; i < stop; ++i)
        if (rems[i] != rems[k - i])
          return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
