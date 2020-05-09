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

// word --> S
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int expressiveWords(string S, vector<string>& words) {
    if (S.empty() || words.empty()) return 0;
    const int m = S.size();
    int res = 0;
    char old = ' ';
    for (const string &word: words) {
      const int n = word.size();
      if (n > m) continue;
      if (m <= 2 || n == m) {res += S == word; continue; }
      if (S.front() != word.front() || S.back() != word.back()) continue;
      int i = 0, j = 0;
      while (j < n) {
        if (S[i] == word[j]) {
          old = word[j];
          ++i; ++j;
          continue;
        }

        // S[i] != word[j]
        if (S[i] != old) break;

        // S[i] == old, S = "aaaa", word = "aaa"
        int l = i;
        while (l >= 0 && S[l] == old) --l;
        while (i < m && S[i] == old) ++i;
        if (l != 0 || S[l] != old) ++l;
        if (i != m || S[i] != old) --i;
        if (i - l <= 1) break;
        ++i;
      }
      if (j != n) continue;
      if (i == m) {++res; continue; }
      int l = i;
      while (l >= 0 && S[l] == old) --l;
      while (i < m && S[i] == old) ++i;
      if (l != 0 || S[l] != old) ++l;
      if (i != m || S[i] != old) --i;
      if (i - l <= 1) continue;
      if (++i == m) ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  string a = "aaabc";
  vector<string> b = {"aabc", "abc", "abcc"};
  a = "heeelloooo";
  b = {"hello"};
  cout << s.expressiveWords(a, b) << endl;
  return 0;
}
