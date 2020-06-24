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
  string minWindow(string s, string t) {
    const int m = s.size(), n = t.size();
    if (m < n) return "";

    array<int, 'z' + 1> dict;
    dict.fill(0);
    for (const char c: t) ++dict[c];
    string res = "";
    int l = 0, res_len = m + 1, cur_n = 0, start = -1;  // cur_n: current number of chars in target
    for (int i = 0; i < m; ++i) {
      if (--dict[s[i]] >= 0) ++cur_n;
      while (cur_n == n) {
        const int len = i - l + 1;
        if (len < res_len) {
          res_len = len;
          start = l;
        }
        if (++dict[s[l++]] > 0) --cur_n;
      }
    }
    return start == -1? "": s.substr(start, res_len);
  }
};

int main() {
  Solution s;
  
  return 0;
}
