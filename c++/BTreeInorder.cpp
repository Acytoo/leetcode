#include <iostream>
#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  vector<int> res;
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL)
      return {};
    if (root->left != NULL)
      inorderTraversal(root->left);
    if (root != NULL)
      res.push_back(root->val);
    if (root->right != NULL)
      inorderTraversal(root->right);
    return res;
  }
};

int main() {

  Solution s;
  TreeNode *root = new TreeNode(4);
  TreeNode *l1 = new TreeNode(1);
  TreeNode *r1 = new TreeNode(2);
  TreeNode *l2 = new TreeNode(3);
  root->left = l1;
  l1->right = l2;
  root->right = r1;
  vector <int> a;
  root = NULL;
  a = s.inorderTraversal(root);

  for (auto iter = a.cbegin(); iter != a.cend(); iter++)
    cout << *iter << " ";
  cout << endl;
  delete(root);
  delete(l1);
  delete(l2);
  delete(r1);
  return 0;
}
