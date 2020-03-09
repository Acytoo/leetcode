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
  vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    helper(root, res, 0);
    return res;
  }
 private:
  void helper(TreeNode* cur, vector<int>& res, int depth) {
    if (!cur)
      return ;
    if (res.size() <= depth)
      res.push_back(cur->val);
    else if (res[depth] < cur->val)
      res[depth] = cur->val;
    helper(cur->left, res, ++depth);
    helper(cur->right, res, depth);
  }
};

class Solution1 {
 public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if (!root)
      return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int t = q.size(), row_max = INT_MIN;
      while (t--) {
        TreeNode* cur = q.front();
        q.pop();
        row_max = max(row_max, cur->val);
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      res.push_back(row_max);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
