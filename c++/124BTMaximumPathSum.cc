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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>

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
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int res = root->val;
    function<int(TreeNode*)> pathSum =
        [&] (TreeNode *cur) {
          if (!cur) return 0;
          int l = pathSum(cur->left),
              r = pathSum(cur->right);
          int tmp = max({cur->val, cur->val+l, cur->val+r});
          res = max({res, cur->val+l+r, tmp});
          return max({l, r, 0}) + cur->val;
        };
    pathSum(root);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
