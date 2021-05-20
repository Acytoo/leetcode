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


using namespace std;

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of English lowercase letters.

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
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



int main() {
  Solution s;
  vector<string> a = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
  cout << s.longestStrChain(a) << endl;

  return 0;
}
