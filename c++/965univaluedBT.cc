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
  bool isUnivalTree(TreeNode* root) {
    return preorder(root, root->val);
  }
 private:
  bool preorder(TreeNode* cur, int val) {
    if (!cur)
      return true;
    if (cur->val != val)
      return false;
    return preorder(cur->left, val) && preorder(cur->right, val);
  }
};

int main() {
  Solution s;
  
  return 0;
}
