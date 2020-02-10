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
  int distributeCoins(TreeNode* root) {
    int res = 0;
    helper(root, res);
    return res;
  }
 private:
  int helper(TreeNode* root, int& res) {
    if (!root)
      return 0;
    int l = helper(root->left, res);
    int r = helper(root->right, res);
    res += abs(l) + abs(r);
    return l+r+root->val-1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
