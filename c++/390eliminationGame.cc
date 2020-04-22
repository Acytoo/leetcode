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
  int lastRemaining(int n) {
    int res = 1, remain = n, step = 1;
    bool forward = true;
    while (remain > 1) {
      if (forward || (remain&1)==1) res += step;
      remain >>= 1;
      step <<= 1;
      forward ^= true;
    }
    return res;
  }
};


int main() {
  Solution s;
  for (int i=1; i<100; ++i)
    cout << i << " -> " << s.lastRemaining(i) << endl;
  return 0;
}
