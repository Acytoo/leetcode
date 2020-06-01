#include <iostream>
#include <sstream>
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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class Solution {
 public:
  int maxSumBST(TreeNode* root) {
    int res = 0;
    // return tuple {low, high, sum, is_bst}
    function<tuple<int, int, int, bool>(TreeNode*)> dfs =
        [&] (TreeNode *cur) -> tuple<int, int, int, bool> {
      if (!cur) return {INT_MAX, INT_MIN, 0, true};
      auto [ll, lh, ls, lbst] = dfs(cur->left);
      auto [rl, rh, rs, rbst] = dfs(cur->right);
      bool is_bst = lbst && rbst && cur->val < rl && lh < cur->val;
      int sum = is_bst? ls + cur->val + rs: -1;
      res = max(res, sum);
      return {min(ll, cur->val), max(rh, cur->val), sum, is_bst};
    };
    dfs(root);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
