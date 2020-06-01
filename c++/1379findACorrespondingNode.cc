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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// The values of the nodes of the tree are unique.
// Follow up: Solve the problem if repeated values on the tree are allowed.
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    function<TreeNode*(TreeNode*)> getTarget =
        [&] (TreeNode *cur) -> TreeNode* {
          if (!cur) return nullptr;
          if (cur->val == target->val) return cur;
          TreeNode *l = getTarget(cur->left);
          return l? l: getTarget(cur->right);
        };
    return getTarget(cloned);
  }
};

class Solution_follow_up {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    function<bool(TreeNode*, TreeNode*)> isSameTree =
        [&] (const TreeNode *p, const TreeNode *q) {
          if (!p && !q) return true;
          if (!p || !q) return false;
          if (p->val != q->val) return false;
          return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        };
    function<TreeNode*(TreeNode*)> getTarget =
        [&] (TreeNode *cur) -> TreeNode* {
          if (!cur) return nullptr;
          if (cur->val == target->val && isSameTree(cur, target)) return cur;
          TreeNode *l = getTarget(cur->left);
          return l? l: getTarget(cur->right);
        };
    return getTarget(cloned);
  }
};

int main() {
  Solution s;
  
  return 0;
}
