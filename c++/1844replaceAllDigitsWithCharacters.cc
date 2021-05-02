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
  string replaceDigits(string s) {
    auto shift = [] (char c, int i) -> char {
      return c + i;
    };
    for (int i = 1, n = s.size(); i < n; i += 2)
      s[i] = shift(s[i - 1], s[i] - '0');
    return s;
  }
};

int main() {
  Solution s;
  
  return 0;
}
