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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool evaluateTree(TreeNode* root) {
    function<bool(TreeNode*)> helper = [&] (TreeNode *cur) {
      if (cur->val <= 1) return cur->val == 1;
      if (cur->val == 2) return helper(cur->left) || helper(cur->right); // or
      return helper(cur->left) && helper(cur->right);  // and
    };
    if (!root) return true;
    return helper(root);
  }
};

class Solution_SAME_OLD_STANDARD {
 public:
  bool evaluateTree(TreeNode* root) {
    return helper(root);
  }
 private:
  bool helper(TreeNode *cur) {
    if (!cur) return true;
    if (cur->val <= 1) return cur->val == 1;
    if (cur->val == 2) return helper(cur->left) || helper(cur->right);
    return helper(cur->left) && helper(cur->right);
  }
};

int main() {
  Solution s;
  
  return 0;
}
