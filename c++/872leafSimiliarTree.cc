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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> a, b;
    findLeaves(root1, a);
    findLeaves(root2, b);
    int n1 = a.size(), n2 = b.size();
    if (n1 != n2)
      return false;
    for (int i=0; i<n1; ++i) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }
 private:
  void findLeaves(TreeNode* root, vector<int>& a) {
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode* cur = s.top();
      s.pop();

      if (!cur->left && !cur->right) {
        a.push_back(cur->val);
        continue;
      }
      if (cur->left)
        s.push(cur->left);
      if (cur->right)
        s.push(cur->right);

    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
