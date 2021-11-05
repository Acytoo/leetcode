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

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    int res = 0;
    function<void(TreeNode*, int)> helper = [&] (TreeNode *cur, int fv) {
      int val = fv * 10 + cur->val;
      if (!cur->left && !cur->right) {
        res += val;
        return;
      }
      if (cur->left) helper(cur->left, val);
      if (cur->right) helper(cur->right, val);
    };
    helper(root, 0);
    return res;
  }
};


class Solution_OLD {
 public:
  int sumNumbers(TreeNode* root) {
    int res = 0, num = 0;
    sumNumbers(root, num, res);
    return res;
  }
 private:
  void sumNumbers(TreeNode* cur, int num, int& res) {
    if (!cur)
      return ;
    num = num * 10 + cur->val;
    if (cur->left || cur->right) {
      sumNumbers(cur->left, num, res);
      sumNumbers(cur->right, num, res);
    } else {
      res += num;
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
