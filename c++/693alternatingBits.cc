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
  bool hasAlternatingBits(int n) {
    int tmp = n & 1;
    n >>= 1;
    while (n != 0) {
      if ((tmp ^ (n&1)) == 0)
        return false;
      tmp = n & 1;
      n >>= 1;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.hasAlternatingBits(11) << endl;
  return 0;
}
