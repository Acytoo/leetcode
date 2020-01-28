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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    int res = 0;
    for (char c: S)
      for (char d: J)
        if (c == d)
          ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
