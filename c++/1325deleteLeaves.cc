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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (root->left)
      root->left = removeLeafNodes(root->left, target);
    if (root->right)
      root->right = removeLeafNodes(root->right, target);
    if (!root->left && !root->right && root->val == target)
      return NULL;
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
