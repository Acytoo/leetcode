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
  string longestNiceSubstring(string s) {
    auto helper = [&] (const int l, const int r) {
      vector<bool> low(26), high(26);
      for (int i = l; i <= r; ++i)
        if (s[i] <= 'Z')
          high[s[i] - 'A'] = true;
        else
          low[s[i] - 'a'] = true;
      return low == high;
    };
    int l = 0, r = 0;
    for (int i = 0, n = s.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (helper(i, j) && (j - i) > (r - l)) {
          l = i;
          r = j;
        }
    return l == r ? "" : s.substr(l, r - l + 1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
