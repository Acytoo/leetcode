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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countSubstrings(string s) {
    const int n = s.size();
    int res = 0;
    function<void(int, int)> helper =
        [&] (int l, int r) {
          while (0 <= l && r < n && s[l] == s[r]) {
            --l; ++r;
            ++res;
          }
        };

    for (int i=0; i<n; ++i) {
      helper(i, i);
      helper(i, i+1);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
