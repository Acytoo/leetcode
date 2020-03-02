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
  int longestUnivaluePath(TreeNode* root) {
    if (!root)
      return 0;
    int res = 0;
    helper(root, res);
    return res;
  }
 private:
  int helper(TreeNode* cur, int& res) {
    if (!cur)
      return 0;
    int l = helper(cur->left, res);
    int r = helper(cur->right, res);
    int ll = 0, rr = 0;  // current node plus it's child if exist and have same value
    if (cur->left && cur->val==cur->left->val)
      ll = l + 1;
    if (cur->right && cur->right->val==cur->val)
      rr = r + 1;
    res = max(res, ll+rr);
    return max(ll, rr);
  }
};

int main() {
  Solution s;
  
  return 0;
}
