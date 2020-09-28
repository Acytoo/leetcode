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
  string modifyString(string s) {
    const int n = s.size(), last_idx = n - 1;
    if (n == 1) {
      if (s == "?") return "a";
      return s;
    }
    auto mod = [&] (const int idx) {
      char pre, post;
      if (idx == 0) {
        pre = 'z';
        post = s[idx + 1];
      } else if (idx == last_idx) {
        pre = s[idx - 1];
        post = 'z';
      } else {
        pre = s[idx - 1];
        post = s[idx + 1];
      }
      char tar = 'a';
      while (tar == pre || tar == post) ++tar;
      s[idx] = tar;
    };
    bool modified = false;
    do {
      modified = false;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
          modified = true;
          mod(i);
        }
      }
    } while (modified);
    return s;
  }
};

int main() {
  Solution s;
  
  return 0;
}
