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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    TreeNode dummy (-1);
    dummy.left = root;
    addRow(&dummy, v, d);
    return dummy.left;
  }
 private:
  void addRow(TreeNode* cur, int val, int left) {
    if (!cur)
      return ;
    if (left == 1) {
      TreeNode* l = new TreeNode (val);
      l->left = cur->left;
      // l->right = nullptr;
      cur->left = l;
      TreeNode* r = new TreeNode (val);
      r->right = cur->right;
      cur->right = r;
      return ;
    }
    addRow(cur->left, val, --left);
    addRow(cur->right, val, left);
  }
};

int main() {
  Solution s;
  
  return 0;
}
