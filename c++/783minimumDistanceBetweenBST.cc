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
  int minDiffInBST(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    vector<int> nums;
    while (!s.empty()) {
      TreeNode* cur = s.top();
      s.pop();
      nums.push_back(cur->val);
      if (cur->left) {
        s.push(cur->left);
      }
      if (cur->right) {
        s.push(cur->right);
      }
    }
    sort(nums.begin(), nums.end());
    int res = nums[1] - nums[0];
    int old = nums[1];
    for (int i=2, stop=nums.size(); i<stop; ++i) {
      int tmp = nums[i] - old;
      if (tmp == 1)
        return 1;
      res = min(res, tmp);
      old = nums[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
