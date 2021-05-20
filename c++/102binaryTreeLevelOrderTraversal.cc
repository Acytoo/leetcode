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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    function<void(TreeNode*, int)> helper = [&] (const TreeNode *cur, int level) {
      if (!cur) return ;
      if (res.size() <= level) res.push_back({});
      res[level].push_back(cur->val);
      helper(cur->left, ++level);
      helper(cur->right, level);
    };
    helper(root, 0);
    return res;
  }
};

class Solution1 {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return res;
  }
 private:
  void levelOrder(TreeNode* cur, int level, vector<vector<int>>& nums) {
    if (!cur)
      return ;
    while (nums.size() <= level)
      nums.push_back({});
    nums[level].push_back(cur->val);
    levelOrder(cur->left, level+1, nums);
    levelOrder(cur->right, level+1, nums);
  }
};
int main() {
  Solution s;
  
  return 0;
}
