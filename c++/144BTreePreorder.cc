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


  // Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s_node;
    TreeNode* p = root;
    while (p || !s_node.empty()) {
      if (p) {
        s_node.push(p);
        res.push_back(p->val);
        p = p->left;
      } else {
        p = s_node.top()->right;
        s_node.pop();
      }
    }
    return res;
  }
};

class Solution1 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }
  void dfs(TreeNode* node, vector<int>& res) {
    if (!node)
      return;
    res.push_back(node->val);
    dfs(node->left, res);
    dfs(node->right, res);
  }
};

int main() {
  Solution s;
  TreeNode a = TreeNode(1);
  TreeNode b = TreeNode(2);
  TreeNode c = TreeNode(3);
  // a.left = null;
  a.right = &b;
  b.left = &c;
  // b.right = null;
  vector<int> res = s.preorderTraversal(&a);
  for (auto i : res)
    cout << i << " " ;
  cout << endl;
  return 0;
}
