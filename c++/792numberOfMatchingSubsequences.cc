#include <iostream>
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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numMatchingSubseq(string_view s, vector<string>& words) {
    const int n = s.size();
    auto match = [&] (const string_view &t) -> bool {
      const int m = t.size();
      if (m > n) return false;
      if (m == n) return t == s;
      int i = 0, j = 0;
      for ( ; i < m && j < n; ++j)
        if (t[i] == s[j])
          ++i;
      return i == m;
    };
    int res = 0;
    unordered_map<string_view, int> m;
    for (const string_view &t : words) {
      if (m.count(t)) {
        res += m[t];
      } else {
        const int tmp = match(t);
        m[t] = tmp;
        res += tmp;
      }
    }
    return res;
  }
};

class Solution_TLE {
 public:
  int numMatchingSubseq(string_view s, vector<string>& words) {
    const int n = s.size();
    auto match = [&] (const string_view &t) -> bool {
      const int m = t.size();
      if (m > n) return false;
      if (m == n) return t == s;
      int i = 0, j = 0;
      for ( ; i < m && j < n; ++j)
        if (t[i] == s[j])
          ++i;
      return i == m;
    };
    int res = 0;
    for (const string &t : words) res += match(t);
    return res;
  }
};

class Solution_old {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    // add a map as catch
    int res = 0, n = S.size();
    unordered_map<string, bool> m;
    for (const string& t: words) {
      if (t.size() > n)
        continue;
      auto it = m.find(t);
      if (it == m.end()) {  // new word
        bool flag = match(S, t);
        m[t] = flag;
        res += flag;
      } else {
        res += it->second;
      }
    }
    return res;
  }
 private:
  bool match(const string& s, const string& t) {
    int m = s.size(), n = t.size(), i = 0, j = 0;
    while (i < m) {
      if (s[i] == t[j]) {
        ++i; ++j;
        if (j == n)
          return true;
      } else {
        ++i;
      }
    }
    return false;
  }
};

class Solution_TLE {
  // TLE: many same words ("wp") when S = "wwwwwwwwwwwww...."
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int res = 0, n = S.size();
    for (const string& t: words)
      if (t.size() <= n && match(S, t))
        ++res;
    return res;
  }
 private:
  bool match(const string& s, const string& t) {
    int m = s.size(), n = t.size(), i = 0, j = 0;
    while (i < m) {
      if (s[i] == t[j]) {
        ++i; ++j;
        if (j == n)
          return true;
      } else {
        ++i;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  string a = "abcde";
  vector<string> b = {"a", "ac", "ad", "bb", "ce", "abcdee"};
  cout << s.numMatchingSubseq(a, b) << endl;
  return 0;
}
