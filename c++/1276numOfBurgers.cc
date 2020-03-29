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
  vector<int> numOfBurgers(int t, int c) {
    if ((t&1) || t < (c<<1) || t > (c<<2))
      return {};
    // if (t == (c<<1))
    //   return {0, c};
    // if (t == (c<<2))
    //   return {c, 0};
    return {(t>>1)-c, (c<<1) - (t>>1)};
  }
};

int main() {
  Solution s;
  
  return 0;
}
