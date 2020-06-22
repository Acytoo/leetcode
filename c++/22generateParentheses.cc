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
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    cur.reserve(n << 1);
    function<void(int, int)> dfs =
        [&] (const int l, const int r) {  // how many '(' and ')' left
          if (l + r == 0) {
            res.push_back(cur);
            return ;
          }
          if (r < l) return ;
          if (0 < l) {
            cur.push_back('(');
            dfs(l - 1, r);
            cur.pop_back();
          }
          if (0 < r) {
            cur.push_back(')');
            dfs(l, r - 1);
            cur.pop_back();
          }
        };
    dfs(n, n);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
