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
// in-place
class Solution {
 public:
  void flatten(TreeNode* root) {
    helper(root);
  }
 private:
  TreeNode*  helper(TreeNode* cur) {
    if (!cur)
      return nullptr;
    TreeNode* l = helper(cur->left);
    TreeNode* r = helper(cur->right);

    if (cur->left) {
      TreeNode* tmp = cur->right;
      cur->right = cur->left;
      cur->left = nullptr;
      l->right = tmp;
    }
    if (r)
      return r;
    if (l)
      return l;
    return cur;
  }
};

int main() {
  Solution s;
  
  return 0;
}
