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
// rob(root) = max(root.val+rob(ll)+rob(lr)+rob(rr)+rob(rl), rob(l)+rob(r))
class Solution {
public:
  int rob(TreeNode* root) {
    vector<int> money = helper(root);
    return max(money[0], money[1]);
  }
 private:
  vector<int> helper(TreeNode* root) {
    if (!root)
      return {0, 0};
    vector<int> l = helper(root->left);
    vector<int> r = helper(root->right);
    return {root->val+l[1]+r[1], max(l[0], l[1])+max(r[0], r[1])};
  }
};

int main() {
  Solution s;
  
  return 0;
}
