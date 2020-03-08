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
class FindElements {
 public:
  FindElements(TreeNode* root) {
    root_ = root;
    buildTree(root, 0);
  }

  bool find(int target) {
    return find(root_, target);
  }
 private:
  TreeNode* root_;

  void buildTree(TreeNode* cur, int val) {
    if (!cur)
      return ;
    cur->val = val;
    val <<= 1;
    buildTree(cur->left, ++val);
    buildTree(cur->right, ++val);
  }

  bool find(TreeNode* cur, int target) {
    if (!cur)
      return false;
    if (cur->val == target)
      return true;
    if (cur->val > target)
      return false;
    return find(cur->left, target) || find(cur->right, target);
  }
};

int main() {
  Solution s;
  
  return 0;
}
