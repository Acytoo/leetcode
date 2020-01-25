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
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode* newCur = new TreeNode(-1);
    TreeNode* res = newCur;
    TreeNode* cur = root;
    stack<TreeNode*> s;
    while (cur != NULL || !s.empty()) {
      while (cur != NULL) {
        s.push(cur);
        cur = cur->left;
      }
      if (!s.empty()) {
        cur = s.top();
        TreeNode* newNode = new TreeNode(cur->val);
        newCur->right = newNode;
        newCur = newCur->right;
        s.pop();
        cur = cur->right;
      }
    }
    cout << endl;
    return res->right;
  }
};

int main() {
  Solution s;
  
  return 0;
}
