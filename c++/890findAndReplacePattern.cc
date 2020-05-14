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
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    constexpr int kSize = 'z' + 1;
    const int m = pattern.size();
    function<bool(string&)> biject =
        [&] (string &word) {
          bitset<kSize> y;
          map<char, char> xy;
          int i = 0, n = min(m, static_cast<int>(word.size()));
          while (i < n) {
            if (xy.count(word[i])) {
              if (pattern[i] != xy[word[i]]) return false;
              ++i;
            } else {
              if (y[pattern[i]]) return false;
              y[pattern[i]] = 1;
              xy[word[i]] = pattern[i];
            }
          }
          return true;
        };
    vector<string> res;
    for (string &word: words)
      if (biject(word))
        res.emplace_back(move(word));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
