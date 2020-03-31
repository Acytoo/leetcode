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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  // Math
  int mirrorReflection(int p, int q) {
    while ((p&1)==0 && (q&1)==0) {
      p >>= 1;
      q >>= 1;
    }

    if ((p&1)==0 && (q&1)==1)
      return 2;

    if ((p&1)==1 && (q&1)==1)
      return 1;

    return 0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
