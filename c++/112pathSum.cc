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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
      return false;
    if (!root->left && !root->right)
      return root->val == sum;

    int summ = sum - root->val;
    return hasPathSum(root->left, summ) || hasPathSum(root->right, summ);
  }
};

int main() {
  Solution s;
  
  return 0;
}
