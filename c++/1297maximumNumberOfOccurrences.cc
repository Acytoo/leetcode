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
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int res = 0;
    unordered_map<string, int> m;
    for (int i = 0, n = s.size(); i < n; ++i) {
      unordered_set<char> chars;
      string cur;
      for (int j = i, stop = min(n, i + maxSize); j < stop; ++j) {
        chars.insert(s[j]);
        if (chars.size() > maxLetters) break;
        cur += s[j];
        if (j - i + 1 >= minSize) res = max(res, ++m[cur]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
