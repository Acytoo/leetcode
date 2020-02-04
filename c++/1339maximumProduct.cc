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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int maxProduct(TreeNode* root) {
    const int k_mod = 1e9+7;
    long sum = 0;
    long res = 0;
    function<int(TreeNode*)> calSum = [&] (TreeNode* root) {
                                        if (!root)
                                          return 0;
                                        int sum_l = calSum(root->left);
                                        int sum_r = calSum(root->right);
                                        if (root)
                                          res = max({res, (sum-sum_l)*sum_l, (sum-sum_r)*sum_r});
                                        return root->val + sum_l + sum_r;
                                      };
    s = calSum(root);
    calSum(root);
    return res % k_mod;
  }
};

int main() {
  Solution s;
  
  return 0;
}
