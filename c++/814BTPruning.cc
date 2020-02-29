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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root)
      return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val==1 || root->left || root->right)
      return root;
    delete root;
    return nullptr;
  }
};

int main() {
  Solution s;
  
  return 0;
}
