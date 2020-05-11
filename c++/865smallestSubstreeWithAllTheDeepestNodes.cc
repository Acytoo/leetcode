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
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    TreeNode *res;
    function<int(TreeNode*, TreeNode**)> depth =
        [&] (TreeNode *cur, TreeNode **res) {
          if (!cur) return -1;
          TreeNode *ll = nullptr, *rr = nullptr;
          int l = depth(cur->left, &ll), r = depth(cur->right, &rr);
          *res = l == r? cur: l < r? rr: ll;
          return max(l, r) + 1;
        };
    depth(root, &res);
    return res;
  }
};

class Solution_WRONG {
 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    TreeNode *res = nullptr;
    int max_depth = -1;
    function<int(TreeNode*)> maxDepth =
        [&] (TreeNode *cur) {
          if (!cur) return -1;
          int l = maxDepth(cur->left), r = maxDepth(cur->right);
          if (l > max_depth || r > max_depth) {
            max_depth = max(l, r);
            if (l == r)
              res = cur;
            else if (l < r)
              res = cur->right;
            else
              res = cur->left;
          }
          // if (l == r && l > max_depth) {res = cur; max_depth = l; }
          return max_depth + 1;
        };
    maxDepth(root);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
