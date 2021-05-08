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
  int superpalindromesInRange(string left, string right) {
    auto isPalindrome = [] (string_view a) ->bool {
      for (int l = 0, r = a.size() - 1; l < r; ++l, --r)
        if (a[l] != a[r])
          return false;
      return true;
    };
    int res = 0;
    long long l = stoll(left), r = stoll(right);
    if (l == 1) ++res;
    if (l <= 4 && 4 <= r) ++res;
    if (l <= 9 && 9 <= r) ++res;

    for (int i = 1; i < 10000; ++i) {
      string p1 = to_string(i), p3 = p1;
      reverse(p3.begin(), p3.end());
      long long case1 = stoll(p1 + p3);
      case1 *= case1;
      if (case1 > r) break;
      if (l <= case1 && isPalindrome(to_string(case1)))
        ++res;
      for (char c = '0'; c <= '9'; ++c) {
        long long case2 = stoll(p1 + c + p3);
        case2 *= case2;
        if (case2 > r) break;
        if (l <= case2 && isPalindrome(to_string(case2)))
          ++res;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
