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
  int numTilePossibilities(string tiles) {
    int dict['Z' + 1];
    memset(dict, 0, sizeof(dict));
    for (const char c: tiles) ++dict[c];
    int res = 0;
    function<void(void)> helper =
        [&] () {
          for (char c = 'A'; c <= 'Z'; ++c) {
            if (dict[c] == 0) continue;
            ++res;
            --dict[c];
            helper();
            ++dict[c];
          }
        };
    helper();
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
