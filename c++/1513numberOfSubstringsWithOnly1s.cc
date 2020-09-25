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
// consecutive 1s
// 1: 1;
// 11: 3;
// 111: 6;
// 1111: 10;
// 11111: 15;
// (top + bottom) * high / 2
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numSub(string s) {
    constexpr int kMod = 1e9 + 7;
    long res = 0, cur = 0;
    for (const char c: s) {
      cur = c == '0'? 0: cur + 1;
      res += cur;
    }
    return res % kMod;
  }
};

class Solution1 {
 public:
  int numSub(string s) {
    s += '0';
    constexpr int kMod = 1e9 + 7;
    auto substrs = [] (long x) -> int { return (((1 + x) * x) >> 1) % kMod; };
    int l = -1, r = -1, res = 0;
    for (int i = 0, stop = s.size(); i < stop; ++i)
      if (s[i] == '0') {
        if (l != r) res += substrs(r - l);
        l = r = i;
      } else {
        while (i < stop && s[i] == '1') ++i;
        r = --i;
      }
    return res;
  }
};

class Solution11 {
 public:
  int numSub(string s) {
    s += '0';
    constexpr int kMod = 1e9 + 7;
    auto substrs = [] (long x) -> int { return (((1 + x) * x) >> 1) % kMod; };
    int l = -1, r = -1, res = 0;
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      if (s[i] == '0') {
        if (l == r) {
          l = r = i;
        } else {
          res += substrs(r - l);
          l = r = i;
        }
      } else {
        while (i < stop && s[i] == '1') ++i;
        r = --i;
      }
    }
    return l == r? res: res + substrs(r - l);
  }
};


int main() {
  Solution s;
  
  return 0;
}
