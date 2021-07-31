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

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    function<TreeNode*(int, int)> helper = [&](int l, int r) -> TreeNode* {
      if (r < l)
        return nullptr;
      int m = (l + r) >> 1;
      TreeNode *root = new TreeNode(nums[m]);
      root->left = helper(l, m - 1);
      root->right = helper(m + 1, r);
      return root;
    };
    TreeNode* res = helper(0, nums.size() - 1);
    return res;
  }
};

class Solution1 {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
 private:
  TreeNode* helper(vector<int>& nums, int l, int r) {
    if (r < l)
      return NULL;
    int m = (l + r) >> 1;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = helper(nums, l, m - 1);
    root->right = helper(nums, m + 1, r);
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
