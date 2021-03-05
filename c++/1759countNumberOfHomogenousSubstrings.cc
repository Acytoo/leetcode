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

// 1 :  1 ===> 1 x 1 "a"
// 2 :  3 ===> 1 x 3 "aa"
// 3 :  6 ===> 2 x 3 "aaa"
// 4 : 10 ===> 2 x 5 "aaaa"
// 5 : 15 ===> 3 x 5
// 6 : 21 ===> 3 x 7
// 7 : 28 ===> 4 x 7
// 8 : 36 ===> 4 x 9

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countHomogenous(string s) {
    constexpr int kMod = 1e9 + 7;
    // auto helper = [] (const long x) { return ((x + 1) >> 1) * (((x >> 1) << 1) + 1); };
    auto helper = [] (const long x) { return ((x + 1) >> 1) * (x | 1); };
    char cur = s[0];
    int l = 0, r = 0;
    long res = 0;
    const int n = s.size();
    while (l < n) {
      while (r < n && s[r] == s[l]) ++r;
      res += helper(r - l);
      l = r;
    }
    return static_cast<int> (res % kMod);
  }
};

int main() {
  Solution s;
  
  return 0;
}
