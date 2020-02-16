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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int brokenCalc(int X, int Y) {
    if (Y <= X)
      return X-Y;
    return 1 + brokenCalc(X, (Y&1)? Y+1: Y>>1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
