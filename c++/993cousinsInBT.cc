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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Each node has a unique integer value from 1 to 100
class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    vector<int> heights (101);
    // int depth = 0;
    function<bool(TreeNode*, int)> findDepth =
        [&] (TreeNode *cur, int depth) {
          heights[cur->val] = depth;
          if (cur->left && cur->right)
            if ((cur->left->val == x && cur->right->val == y) ||
                (cur->left->val == y && cur->right->val == x)) return false;
          bool l = true, r = true;
          ++depth;
          if (cur->left) l = findDepth(cur->left, depth);
          if (cur->right) r = findDepth(cur->right, depth);
          return l && r;
        };
    if (!findDepth(root, 0)) return false;
    if (heights[x] == heights[y]) return true;
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
