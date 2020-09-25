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
  int minFlips(string target) {
    int res = 0;
    char pre = '0';
    for (const char cur: target)
      if (cur != pre) {
        ++res;
        pre = cur;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
