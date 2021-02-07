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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Level order traversal
class Solution {  // 2021-02-06
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    function<void(TreeNode*, int)> helper = [&] (TreeNode *cur, int dep) {
      if (!cur) return ;
      if (dep == res.size())
        res.emplace_back(cur->val);
      else
        res[dep] = cur->val;
      helper(cur->left, ++dep);
      helper(cur->right, dep);
    };
    helper(root, 0);
    return res;
  }
};

class Solution1 {  // 2020-03-13
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    helper(root, res, 1);
    return res;
  }
 private:
  void helper(TreeNode* cur, vector<int>& res, int depth) {
    if (!cur)
      return ;
    if (depth > res.size())
      res.push_back(cur->val);
    else
      res[depth-1] = cur->val;
    helper(cur->left, res, ++depth);
    helper(cur->right, res, depth);
  }
};

int main() {
  Solution s;
  
  return 0;
}
