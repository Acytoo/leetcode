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
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root)
      return NULL;

    if (root->val < L)
      return trimBST(root->right, L, R);
    if (R < root->val)
      return trimBST(root->left, L, R);

    root->left = root->val == L? NULL: trimBST(root->left, L, R);
    root->right = root->val == R? NULL: trimBST(root->right, L, R);
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
