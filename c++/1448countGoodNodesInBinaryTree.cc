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
  int goodNodes(TreeNode* root) {
    function<int(TreeNode*, int)> helper =
        [&] (TreeNode *cur, int max_val) -> int {
          if (!cur) return 0;
          int new_max_val = max(max_val, cur->val);
          return helper(cur->left, new_max_val) +
              (cur->val >= max_val? 1: 0) +
              helper(cur->right, new_max_val);
        };
    return helper(root, INT_MIN);
  }
};

int main() {
  Solution s;
  
  return 0;
}
