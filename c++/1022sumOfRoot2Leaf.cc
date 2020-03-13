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
  int sumRootToLeaf(TreeNode* root) {
    int res = 0;
    sumTree(root, res, 0);
    return res;
  }
 private:
  void sumTree(TreeNode* cur, int& res, int val) {
    if (!cur->left && !cur->right) {
      val <<= 1;
      val |= cur->val;
      res += val;
      return ;
    }
    val <<= 1;
    val |= cur->val;
    if (cur->left)
      sumTree(cur->left, res, val);
    if (cur->right)
      sumTree(cur->right, res, val);
  }
};

int main() {
  Solution s;
  
  return 0;
}
