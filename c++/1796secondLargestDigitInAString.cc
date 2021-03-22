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
  int secondHighest(string s) {
    char digit[10];
    memset(digit, 0, sizeof digit);
    for (const char c : s)
      if (c <= '9')
        digit[c - '0'] = 1;
    bool flag = false;
    for (int i = 9; i >= 0; --i)
      if (digit[i]) {
        if (flag)
          return i;
        else
          flag = true;
      }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
