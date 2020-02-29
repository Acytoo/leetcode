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
// runtime is quite strange
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (!root)
      return {};
    vector<vector<int>> res;
    vector<int> cur_path;
    pathSum(root, sum, res, cur_path);
    return res;
  }
 private:
  void pathSum(TreeNode* cur, int sum, vector<vector<int>>& res, vector<int>& cur_path) {
    if (!cur)
      return ;
    if (!cur->left && !cur->right) {
      if (cur->val == sum) {
        res.emplace_back(cur_path.begin(), cur_path.end());
        // res.push_back(cur_path);
        res.back().push_back(cur->val);
      }
      return ;
    }
    cur_path.push_back(cur->val);
    int summ = sum - cur->val;
    pathSum(cur->left, summ, res, cur_path);
    pathSum(cur->right, summ, res, cur_path);
    cur_path.pop_back();
  }
};


int main() {
  Solution s;
  
  return 0;
}
