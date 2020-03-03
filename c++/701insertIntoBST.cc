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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root)
      return new TreeNode (val);
    if (val < root->val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
