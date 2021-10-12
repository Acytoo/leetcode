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
  int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    function<int(TreeNode*)> helper = [&] (TreeNode* cur) -> int {
      if (!cur) return -1;
      int l = helper(cur->left) + 1;
      int r = helper(cur->right) + 1;
      res = max(res, l + r);
      return max(l, r);
    };
    helper(root);
    return res;
  }
};

class Solution1 {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    helper(root, res);
    return res;
  }
 private:
  int helper(TreeNode* cur, int& res) {
    if (!cur)
      return -1;
    int l = helper(cur->left, res) + 1;
    int r = helper(cur->right, res) + 1;
    res = max(res, l+r);
    return max(l, r);
  }
};

int main() {
  Solution s;
  
  return 0;
}
