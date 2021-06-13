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
  vector<vector<int>> palindromePairs(vector<string>& words) {
    auto isPalindrome = [] (const string_view s) {
      for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        if (s[i] != s[j]) return false;
      return true;
    };

    unordered_map<string, int> m;
    vector<vector<int>> res;
    for (int i = 0, n = words.size(); i < n; ++i) m[words[i]] = i;
    for (int i = 0, n = words.size(); i < n; ++i) {
      reverse(words[i].begin(), words[i].end());
      const int len = words[i].size();
      for (int j = 0; j <= len; ++j) {
        string left = words[i].substr(0, j),
              right = words[i].substr(j);
        if (m.count(left) && isPalindrome(right) && m[left] != i)
          res.emplace_back(initializer_list<int>{m[left], i});
        if (m.count(right) && isPalindrome(left) && m[right] != i && j > 0)
          res.emplace_back(initializer_list<int>{i, m[right]});
      }
    }
    return res;
  }
};

class Solution_TLE {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    auto isPalindrome = [&] (const int i, const int j) {
      const string sum = words[i] + words[j];
      for (int i = 0, j = sum.size() - 1; i < j; ++i, --j)
        if (sum[i] != sum[j]) return false;
      return true;
    };
    vector<vector<int>> res;
    for (int i = 0, n = words.size(); i < n; ++i)
      for (int j = 0; j < i; ++j) {
        if (isPalindrome(i, j)) res.emplace_back(initializer_list<int>{i, j});
        if (isPalindrome(j, i)) res.emplace_back(initializer_list<int>{j, i});
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
