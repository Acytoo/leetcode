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
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    function<void(TreeNode*, bool)> helper = [&] (TreeNode *cur, bool l) {
      if (!cur->left && !cur->right) {
        if (l) res += cur->val;
        return;
      }
      if (cur->left) helper(cur->left, true);
      if (cur->right) helper(cur->right, false);
    };
    helper(root, false);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
