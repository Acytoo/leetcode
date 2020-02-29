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
  int getMinimumDifference(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    int res = INT_MAX;
    for (int i=nums.size()-1; 0<i;) {
      int tmp = nums[i] - nums[--i];
      if (tmp == 1)
        return 1;
      res = min(res, tmp);
    }
    return res;
  }
 private:
  void inorder(TreeNode* cur, vector<int>& nums) {
    if (!cur)
      return ;
    inorder(cur->left, nums);
    nums.push_back(cur->val);
    inorder(cur->right, nums);
  }
};

int main() {
  Solution s;
  
  return 0;
}
