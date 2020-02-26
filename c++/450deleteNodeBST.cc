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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>


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
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
      return root;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (root->left && root->right) {
        // 将左子树最大或者右子树最小替换，然后删除这个节点
        TreeNode* min = root->right;
        while (min->left)
          min = min->left;
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
      } else {
        // 只有单个孩子，或者没有孩子。跳过连接，或者旋转
        TreeNode* new_root = root->left? root->left: root->right;
        root->left = root->right = nullptr;
        delete root;
        return new_root;  // 返回nullptr或者新根
      }
    }
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
