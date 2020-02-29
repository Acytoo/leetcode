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
// 指针的引用
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    if (!root)
      return {};
    vector<int> res;
    // res.push_back(root->val);
    int res_count = 0, cur_count = 1;
    TreeNode* pre = nullptr;
    helper(root, pre, cur_count, res_count, res);
    return res;
  }
 private:
  //  inorder
  void helper(TreeNode* cur, TreeNode*& pre,
              int& cur_count, int& res_count, vector<int>& res) {
    if (!cur)
      return ;
    helper(cur->left, pre, cur_count, res_count, res);  // cur->left's pre is cur's pre, eg: [1, nul, 2, 1]

    if (pre)
      cur_count = (pre->val == cur->val)? cur_count+1: 1;

    if (res_count <= cur_count) {
      if (res_count < cur_count) {
        res.clear();
        res_count = cur_count;
      }
      res.push_back(cur->val);
    }
    pre = cur;
    helper(cur->right, pre, cur_count, res_count, res);
  }
};


// midorder, O(n) space
class Solution1 {
 public:
  vector<int> findMode(TreeNode* root) {
    if (!root)
      return {};
    TreeNode* pre = nullptr;
    stack<TreeNode*> s;
    s.push(root);
    vector<int> res;
    int count = 0, res_count = 0;
    while (!s.empty()) {
      TreeNode* cur = s.top();
      s.pop();
      if (pre && pre->val == cur->val) {
        ++count;
        if (count == res_count) {
          res.push_back(cur->val);
        } else if (count > res_count) {
          res.clears();
          res.push_back(cur->val);
          res_count = count;
        }
      } else {
        count = 1;
        pre = cur;
      }

    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
