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
  bool isEvenOddTree(TreeNode* root) {
    vector<int> each_level;
    function<bool(int, TreeNode*)> helper =
        [&] (int level, TreeNode *cur) {
          if (!cur) return true;
          if (!((level ^ (cur->val)) & 1)) return false;

          if (each_level.size() <= level) {
            each_level.emplace_back(cur->val);
            return helper(++level, cur->left) && helper(level, cur->right);
          }
          if (level & 1) {  // odd-indexed level
            if (cur->val >= each_level[level]) return false;
            each_level[level] = cur->val;
          } else {
            if (cur->val <= each_level[level]) return false;
            each_level[level] = cur->val;
          }
          return helper(++level, cur->left) && helper(level, cur->right);
        };
    return helper(0, root);
  }
};


int main() {
  Solution s;
  
  return 0;
}
