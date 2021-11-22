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

#include <cstring>

using namespace std;

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of English lowercase letters.

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // fast
 public:
  int longestStrChain(vector<string>& words) {
    auto pre = [&] (const string_view a, const string_view b) {
      for (int m = a.size() - 1, n = b.size() - 1; m >= 0; --n) {
        if (a[m] == b[n]) { --m; continue; }
        if (m >= n) return false;
      }
      return true;
    };
    vector<vector<string_view>> ws(17);
    int res = 1;
    vector<vector<int>> dp(17);
    for (const auto &a : words) ws[a.size()].emplace_back(a);
    for (int len = 1; len <= 16; ++len)
      for (int i = 0, stopi = ws[len].size(); i < stopi; ++i) {
        dp[len].push_back(1);
        const int pre_len = len - 1;
        for (int j = 0, stopj = ws[pre_len].size(); j < stopj; ++j)
          if (pre(ws[pre_len][j], ws[len][i]))
            dp[len][i] = max(dp[len][i], dp[pre_len][j] + 1);
        res = max(res, dp[len][i]);
      }
    return res;
  }
};



class Solution_veryslow {
 public:
  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [&] (const string_view a, const string_view b) {
      return a.size() < b.size();
    });
    unordered_map<string_view, int> m;
    int res = 0;
    for (const string &a : words) {
      for (int i = 0, n = a.size(); i < n; ++i) {
        auto pre = a.substr(0, i) + a.substr(i + 1);
        m[a] = max(m[a], m[pre] + 1);
      }
      res = max(res, dp[a]);
    }
    return res;
  }
};


class Solution_faster {
 public:
  int longestStrChain(vector<string>& words) {
    auto pre = [&] (string &a, string &b) ->bool {  // a is shorter than b
      bool flag = false;
      for (int i = 0, j = 0, n = a.size(); i < n; ++i, ++j)
        if (a[i] != b[j]) {
          if (flag) { return false; }
          else { --i; flag = true; }
        }
      return true;
    };
    vector<vector<string>> ws(17);
    for (const string &w : words)
      ws[w.size()].emplace_back(move(w));
    vector<vector<int>> dp(17);
    int res = 1;
    for (int i = 1; i <= 16; ++i) {
      if (i - 1 < 0 || ws[i - 1].empty()) {
        for (int j = 0, stop = ws[i].size(); j < stop; ++j)
          dp[i].push_back(1);
      } else {
        for (int j = 0, stopj = ws[i].size(); j < stopj; ++j) {
          dp[i].push_back(1);
          for (int k = 0, stopk = ws[i - 1].size(); k < stopk; ++k) {
            if (pre(ws[i - 1][k], ws[i][j]))
              dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
          }
          res = max(res, dp[i][j]);
        }
      }
    }
    return res;
  }
};

class Solution_slower {
 public:
  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [&] (const string &a, const string &b) {
      return a.size() < b.size();
    });
    // auto pre = [&] (string_view a, string_view b) -> bool {  // a is shorter
    //   int m = a.size() - 1, n = b.size() - 1;
    //   if (m != n - 1) return false;
    //   bool skip = false;
    //   while (m >= 0) {
    //     if (a[m] == b[n]) {
    //       --m;
    //       --n;
    //       continue;
    //     }
    //     if (skip) return false;
    //     --n;
    //     skip = true;
    //   }
    //   return true;
    // };
    auto pre = [&] (string &a, string &b) ->bool {  // a is shorter than b
      if (a.size() != b.size() - 1) return false;
      bool flag = false;
      for (int i = 0, j = 0, n = a.size(); i < n; ++i, ++j)
        if (a[i] != b[j]) {
          if (flag) { return false; }
          else { --i; flag = true; }
        }
      return true;
    };
    vector<int> dp(words.size(), 1);
    for (int i = 1, n = words.size(); i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (pre(words[j], words[i]))
          dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
  }
};


class Solution_OLD {
 public:
  int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), [&](const string& a, const string& b) {
      return a.size() < b.size();
    });
    // for (const string& a: words)
    // cout << a  << " ";
    // cout << endl;
    vector<int> dp (n, 1);
    for (int i=0; i<n; ++i)
      for (int j=0; j<i; ++j)
        if (pre(words[j], words[i]))
          dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
  }
 private:
  bool pre(const string& a, const string& b) const {
    int m = a.size()-1, n = b.size()-1;
    if (n-m != 1)
      return false;
    int diff = 0;
    while (m >= 0 && n >= 0) {
      if (a[m] == b[n]) {
        --m;
        --n;
      } else {
        ++diff;
        if (diff > 1)
          return false;
        --n;
      }
    }
    // cout << a << " " << b << " " << diff << endl;
    return diff <= 1;
  }
};

class Solution_WA {
 public:
  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [&] (const string &a, string &b) {
      return a.size() < b.size();
    });
    auto pre = [&] (const int i, const int j) -> bool {
      const int m = words[i].size(), n = words[j].size();
      if (m != n - 1) return false;
      int letters['z' + 1];
      memset(letters, 0, sizeof letters);
      for (const char c : words[j]) ++letters[c];
      for (const char c : words[i]) --letters[c];
      bool has_diff = false;
      for (char c = 'a'; c <= 'z'; ++c) {
        if (letters[c] < 0 || letters[c] > 1) return false;
        if (letters[c] == 1) {
          if (has_diff)
            return false;
          else
            has_diff = true;
        }
      }
      return true;
    };
    vector<int> dp (words.size(), 1);
    for (int i = 0, n = words.size(); i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (pre(j, i))
          dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
  }
};

class Solution_WA__________ {
 public:
  int longestStrChain(vector<string>& words) {
    vector<vector<string_view>> ws(17);
    for (const string_view a : words) ws[a.size()].emplace_back(a);
    auto pre = [&] (const string_view a, const string_view b) {
      for (int m = a.size() - 1, n = b.size() - 1; m >= 0; )
        if (a[m] == b[n]) {
          --m; --n;
        } else {
          --n;
          if (m > n) return false;
        }
      return true;
    };
    vector<vector<int>> dp(17);
    int res = 1;
    for (int len = 1; len <= 16; ++len) {
      const int pre_len = len - 1;
      if (ws[pre_len].empty()) {
        for (int i = 0, stop = ws[len].size(); i < stop; ++i)
          dp[i].emplace_back(1);
        continue;
      }
      for (int i = 0, stopi = ws[len].size(); i < stopi; ++i) {
        dp[len].emplace_back(1);
        for (int j = 0, stopj = ws[pre_len].size(); j < stopj; ++j)
          if (pre(ws[pre_len][j], ws[len][i])) {
            dp[len][i] = max(dp[len][i], dp[pre_len][j] + 1);
            res = max(res, dp[len][i]);
          }
      }
    }
    return res;
  }
};



int main() {
  Solution s;
  vector<string> a = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
  // a = {"abcd","dbqca"};
  cout << s.longestStrChain(a) << endl;

  return 0;
}
