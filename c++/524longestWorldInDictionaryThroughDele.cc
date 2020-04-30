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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(), [](const string &a, const string &b) {
                               int aa = a.size(), bb = b.size();
                               return aa != bb? aa > bb : a < b;
                             });

    const int n = s.size();
    function<bool(string)> match =
        [&] (const string &t) {
          int i = 0, j = 0, m = t.size();  // target(i, m), source(j, n)
          while (j < n) {
            if (i == m) return true;
            if (s[j] == t[i]) ++i;
            ++j;
          }
          return i == m;
        };

    for (string &a: d) {
      if (n < a.size()) continue;
      if (match(a)) return a;
    }
    return "";
  }
};

int main() {
  Solution s;
  
  return 0;
}
