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
class Solution {
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
