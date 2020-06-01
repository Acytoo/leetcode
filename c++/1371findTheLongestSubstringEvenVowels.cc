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
  int findTheLongestSubstring(string s) {
    // bitset<'z' + 1> is_vowel;
    // is_vowel['a'] = 1; is_vowel['e'] = 1; is_vowel['i'] = 1;
    // is_vowel['o'] = 1; is_vowel['u'] = 1;
    constexpr char vowels[] = "aeiou";
    vector<int> idx (1 << 5, INT_MAX);
    idx[0] = -1;
    int res = 0, cur = 0, state = 0;
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      for (int j = 0; j < 5; ++j)
        if (s[i] == vowels[j]) state ^= (1 << j);
      if (idx[state] == INT_MAX)
        idx[state] = i;
      else
        res = max(res, i - idx[state]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
