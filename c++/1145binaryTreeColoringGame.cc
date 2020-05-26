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

// root is the root of a binary tree with n nodes and distinct node values from 1 to n.
// n is odd.
// 1 <= x <= n <= 100

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    int red_left = 0, red_right = 0;
    function<int(TreeNode*)> countNodes =
        [&] (TreeNode *cur) {
          if (!cur) return 0;
          int count_left = countNodes(cur->left),
             count_right = countNodes(cur->right);
          if (cur->val == x) {
            red_left = count_left;
            red_right = count_right;
          }
          return count_left + count_right + 1;
        };
    countNodes(root);
    int rest = n - 1 - red_left - red_right;  // 1 for node with value x, which is red
    return red_left + red_right + 1 < rest || red_left + 1 + rest < red_right || red_right + 1 + rest < red_left;
  }
};

int main() {
  Solution s;
  
  return 0;
}
