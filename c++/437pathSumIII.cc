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
// How many paths
class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (!root)
      return 0;
    return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
 private:
  int helper(TreeNode* cur, int sum) {
    if (!cur)
      return 0;
    sum -= cur->val;
    return (sum==0? 1: 0) + helper(cur->left, sum) + helper(cur->right, sum);
  }
};


int main() {
  Solution s;
  
  return 0;
}
