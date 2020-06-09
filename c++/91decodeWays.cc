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
// From huahua
class Solution {
 public:
  int numDecodings(string s) {
    const int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    if (n == 1) return 1;
    int w1 = 1, w2 = 1, i = 0;
    auto one = [&] () {return s[i] != '0'; };
    auto two = [&] () {
                 const int num = (s[i - 1] - '0') * 10 + s[i] - '0';
                 return 10 <= num && num <= 26;
               };

    while (++i < n) {
      int w = 0;
      if (!one() && !two()) return 0;
      if (one()) w = w1;
      if (two()) w += w2;
      w2 = w1;
      w1 = w;
    }
    return w1;
  }
};

class Solution_TLE {
 public:
  int numDecodings(string s) {
    const int n = s.size();
    int res;
    function<void(int)> dfs =
        [&] (int idx) {
          if (idx == n) {
            ++res;
            return ;
          }
          if (s[idx] == '0') return ;
          dfs(idx + 1);
          if ((idx + 1 < n) && (s[idx] < '2' || (s[idx] < '3' && s[idx + 1] < '7')))
            dfs(idx + 2);
        };

    dfs(0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
