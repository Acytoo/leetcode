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
  bool checkPartitioning(string s) {
    const int n = s.size();
    vector<vector<bool>> dp (n, vector<bool> (n, true));
    for (int l = 2; l < n; ++l)  // l: length of each sub string
      for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
        dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);

    for (int i = 0, n = s.size() - 1; i < n; ++i)  // n means last index in the folling loops
      for (int j = i + 1; j < n; ++j)
        if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n])
          return true;
    return false;
  }
};

//  *** | **** | **** ==> [0, i], [i + 1, j], [j + 1, n], string length: n + 1
// "abcbdd" ==> i = 0, j = 3
class Solution_TLE {
 public:
  bool checkPartitioning(string s) {
    auto isPalindrome = [&] (int l, int r) {
      if (l > r) return false;
      while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
      }
      return true;
    };
    for (int i = 0, n = s.size() - 1; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (isPalindrome(0, i) && isPalindrome(i + 1, j) && isPalindrome(j + 1, n))
          return true;
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
