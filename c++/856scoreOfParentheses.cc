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
  int scoreOfParentheses(string S) {
    function<int(int, int)> helper =
        [&] (const int l, const int r) -> int {  // [l, r]
          if (r - l == 1) return 1;
          for (int i = l, par = 0; i < r; ++i) {
            if (S[i] == '(')
              ++par;
            else
              --par;
            if (par == 0)
              return helper(l, i) + helper(i + 1, r);
          }
          return helper(l + 1, r - 1) << 1;
        };
    return helper(0, S.size() - 1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
