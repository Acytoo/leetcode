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
  vector<vector<string>> partition(string s) {
    const int n = s.size();
    vector<vector<string>> res;
    vector<string> cur;
    auto palindrome =
        [&] (int l, int r) {
          while (l < r)
            if (s[l++] != s[r--]) return false;
          return true;
        };
    function<void(int)> dfs =
        [&] (const int idx) {
          if (idx == n) {
            res.push_back(cur);
            return ;
          }
          for (int i = idx; i < n; ++i)
            if (palindrome(idx, i)) {
              cur.emplace_back(s.substr(idx, i - idx + 1));
              dfs(i + 1);
              cur.pop_back();
            }
        };
    dfs(0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
