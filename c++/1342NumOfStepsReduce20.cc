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
  int numberOfSteps (int num) {
    int res = 0;
    while (num) {
      if ((num & 1) == 1)
        --num;
      else
        num >>= 1;
      ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
