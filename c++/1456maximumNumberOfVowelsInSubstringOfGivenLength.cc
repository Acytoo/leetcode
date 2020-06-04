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
  int maxVowels(string s, int k) {
    bitset<'z' + 1> vowel;
    vowel['a'] = 1; vowel['e'] = 1;
    vowel['i'] = 1; vowel['o'] = 1; vowel['u'] = 1;
    int cur = 0, res = 0;
    for (int i = 0; i < k; ++i) cur += vowel[s[i]];
    if ((res = cur) == k) return k;
    for (int i = k, stop = s.size(); i < stop; ++i) {
      cur = cur - vowel[s[i - k]] + vowel[s[i]];
      res = max(res, cur);
      if (res == k) return k;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
