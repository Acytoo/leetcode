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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    return buildTree(nums, 0, nums.size()-1);
  }
 private:
  void inorder(TreeNode* cur, vector<int>& nums) {
    if (!cur)
      return ;
    inorder(cur->left, nums);
    nums.push_back(cur->val);
    inorder(cur->right, nums);
  }
  // Balanced BST
  TreeNode* buildTree(vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    int m = (l+r) >> 1;
    TreeNode* root = new TreeNode (nums[m]);
    root->left = buildTree(nums, l, m-1);
    root->right = buildTree(nums, m+1, r);
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
