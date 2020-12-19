#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();


// * Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从leetcode上看到的很快的代码， 也是中序遍历
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* last = nullptr;
    while (root|| !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      if(last != nullptr && last->val >= root->val)
        return false;
      last = root;
      root = root->right;
    }
    return true;
  }
};

// 先序遍历直接比较， 对已二叉搜索数来说，其中旭遍历一定是最快的
class Solution2 {
 public:
  bool isValidBST(TreeNode* root) {
    TreeNode* pre = nullptr;
    return inorder(root, pre);
  }

  bool inorder(TreeNode* node, TreeNode*& pre) {
    if (!node)
      return true;
    if (!inorder(node->left, pre))
      return false;
    if (pre && node->val <= pre->val)
      return false;
    pre = node;
    return inorder(node->right, pre);
  }
};

// 深度优先遍历搜索比较
class Solution1 {
 public:
  bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
  }
  bool dfs(TreeNode* root, long left_wall, long right_wall) {
    if (!root)
      return true;
    if (root->val <= left_wall || right_wall <= root->val)
      return false;
    return dfs(root->left, left_wall, root->val) && dfs(root->right, root->val, right_wall);
  }
};

int main() {
  Solution s;
  
  return 0;
}
