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
// sample input "1-2--3--4-5--6--7"
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* recoverFromPreorder(string S) {
    const int n = S.size();
    int idx = 0;
    function<int(void)> get_depth =
        [&] () {
          int res = 0;
          while (idx < n && S[idx] == '-') {
            ++res;
            ++idx;
          }
          return res;
        };
    function<int(void)> get_value =
        [&] () {
          int res = 0;
          while (idx < n && isdigit(S[idx])) {
            res = res * 10 + S[idx] - '0';
            ++idx;
          }
          return res;
        };
    function<TreeNode*(int)> build =
        [&] (int cur_depth) ->TreeNode* {
          if (idx >= n) return nullptr;
          const int depth = get_depth();
          if (depth != cur_depth) {
            idx -= depth;
            return nullptr;
          }
          TreeNode *cur = new TreeNode (get_value());
          cur->left = build(cur_depth + 1);
          cur->right = build(cur_depth + 1);
          return cur;
        };
    return build(0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
