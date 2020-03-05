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
// same as 538
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* bstToGst(TreeNode* root) {
    TreeNode dummy (-1);
    dummy.left = root;
    int greater = 0;
    rinorder(root, greater);
    return dummy.left;
  }
 private:
  void rinorder(TreeNode* cur, int& greater) {
    if (!cur)
      return ;
    rinorder(cur->right, greater);
    cur->val += greater;
    greater = cur->val;
    rinorder(cur->left, greater);
  }
};

int main() {
  Solution s;
  
  return 0;
}
