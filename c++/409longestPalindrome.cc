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
  int longestPalindrome(string s) {
    vector<int> dict ('z' + 1);
    for (const char c: s) ++dict[c];
    bool odd = false;
    int res = 0;
    for (int i = 'A'; i <= 'z'; ++i)
      if (dict[i] & 1) {
        odd = true;
        res += dict[i] - 1;
      } else {
        res += dict[i];
      }
    return res + odd;
  }
};

int main() {
  Solution s;
  
  return 0;
}
