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
  int maxAncestorDiff(TreeNode* root) {
    int cur_min = INT_MAX, cur_max = INT_MIN, res = 0;
    helper(root, cur_min, cur_max, res);
    return res;
  }
 private:
  void helper(TreeNode* cur, int cur_min, int cur_max, int& res) {
    if (!cur)
      return ;
    if (cur->val < cur_min)
      cur_min = cur->val;
    if (cur->val > cur_max)
      cur_max = cur->val;
    res = (cur_min!=INT_MAX && cur_max!=INT_MIN)? max(res, cur_max-cur_min): 0;
    helper(cur->left, cur_min, cur_max, res);
    helper(cur->right, cur_min, cur_max, res);
  }
};

int main() {
  Solution s;
  
  return 0;
}
