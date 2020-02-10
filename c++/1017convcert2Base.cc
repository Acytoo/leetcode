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
  string baseNeg2(int N) {
    if (N == 0)
      return "0";
    string s;
    while (N) {
      s = to_string(N & 1) + s;
      N = -(N >> 1);
    }
    return s;
  }
};

int main() {
  Solution s;
  
  return 0;
}
