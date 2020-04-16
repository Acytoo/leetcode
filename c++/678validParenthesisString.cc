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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool checkValidString(string s) {
    int low = 0, up = 0;
    for (const char &c: s) {
      if (c == '(') {
        ++low;
        ++up;
      } else if (c == ')') {
        low = low? low-1: 0;
        --up;
      } else {  // '*'
        low = low? low-1: 0;
        ++up;
      }

      if (up < 0) return false;
    }
    return low <= 0 && 0<= up;
  }
};

int main() {
  Solution s;
  
  return 0;
}
