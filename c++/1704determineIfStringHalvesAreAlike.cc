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
  bool halvesAreAlike(string s) {
    bool vowel['z' + 1];
    memset(vowel, 0, sizeof(vowel));
    vowel['A'] = 1; vowel['E'] = 1; vowel['I'] = 1; vowel['O'] = 1; vowel['U'] = 1;
    vowel['a'] = 1; vowel['e'] = 1; vowel['i'] = 1; vowel['o'] = 1; vowel['u'] = 1;
    const int m = s.size() >> 1;
    int l = 0, r = 0;
    for (int i = 0; i < m; ++i)
      if (vowel[s[i]])
        ++l;
    for (int i = s.size() - 1; i >= m; --i)
      if (vowel[s[i]])
        ++r;
    return l == r;
  }
};

class Solution1 {  // 4ms
 public:
  bool halvesAreAlike(string s) {
    bitset<128> vowel;
    vowel['A'] = 1; vowel['E'] = 1; vowel['I'] = 1; vowel['O'] = 1; vowel['U'] = 1;
    vowel['a'] = 1; vowel['e'] = 1; vowel['i'] = 1; vowel['o'] = 1; vowel['u'] = 1;
    const int m = s.size() >> 1;
    int l = 0, r = 0;
    for (int i = 0; i < m; ++i)
      if (vowel[s[i]])
        ++l;
    for (int i = s.size() - 1; i >= m; --i)
      if (vowel[s[i]])
        ++r;
    return l == r;
  }
};

int main() {
  Solution s;
  
  return 0;
}
