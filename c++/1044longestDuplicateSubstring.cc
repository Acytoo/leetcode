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

// 2 <= S.length <= 10^5. The only reason why this question is considered hard
// Robin-Karp hash, solution came from leetcode-cn official
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string longestDupSubstring(string S) {
    constexpr unsigned long kMod = 4294967296;  // kMod has to be big enough(due to collision, false positive)
    const int n = S.size();
    vector<int> nums;
    nums.reserve(n);
    for (const char c: S) nums.emplace_back(c - 'a'); // convert string to nums array

    function<int(int)> search =
        [&] (const int len) {
          unsigned long h = 0;  // hash
          unordered_set<unsigned long> uset;
          for (int i = 0; i < len; ++i) h = (h * 26 + nums[i]) % kMod;
          uset.insert(h);
          unsigned long al = 1;  // const value to be used often: a^len % kMod
          for (int i = 0; i < len; ++i) al = (al * 26) % kMod;

          for (int i = 0, stop = n - len; i < stop; ) {
            h = (h * 26 - nums[i] * al + kMod + nums[i + len]) % kMod;
            ++i;
            if (uset.count(h))
              return i;
            else
              uset.insert(h);
          }
          return -1;
        };
    int l = 1, r = n;
    while (l < r) {
      int m = (l + r) >> 1;
      if (search(m) != -1)
        l = m + 1;
      else
        r = m;
    }
    --l;
    return S.substr(search(l), l);
  }
};

int main() {
  Solution s;
  string a = "abababababab";
  a = "bananabananananananananananana";
  cout << s.longestDupSubstring(a) << endl;
  return 0;
}
