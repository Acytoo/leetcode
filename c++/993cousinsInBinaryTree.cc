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
class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    int dx = 0, dy = 0;
    TreeNode *px = nullptr, *py = nullptr;
    function<void(TreeNode*, TreeNode*, int)> helper
        = [&] (TreeNode *cur, TreeNode *par, int dep) {
      if (!cur) return;
      if (cur->val == x) {
        px = par;
        dx = dep;
      } else if (cur->val == y) {
        py = par;
        dy = dep;
      }
      if (dx != 0 && dy != 0) return;
      helper(cur->left, cur, ++dep);
      helper(cur->right, cur, dep);
    };
    helper(root, nullptr, 0);
    if (px != py && dx == dy) return true;
    return false;
  }
};


// 看自己一年半前写的代码，一点印象也没有……
// 想了许久，应该是其他树的题目有类似的代码直接拿过来一部分……
// 重写一下，优化一下空间复杂度
// Each node has a unique integer value from 1 to 100
class Solution_OLD {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    vector<int> heights (101);
    // int depth = 0;
    function<bool(TreeNode*, int)> findDepth = [&] (TreeNode *cur, int depth) {
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int main() {
  Solution s;
  
  return 0;
}
