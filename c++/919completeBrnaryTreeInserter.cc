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
// level order traversal
class CBTInserter {
 public:
  CBTInserter(TreeNode* root): root_(root), q_({root}) { }

  int insert(int v) {
    while (!q_.empty()) {
      TreeNode* r = q_.front();
      if (r->left && r->right) {
        q_.push(r->left);
        q_.push(r->right);
        q_.pop();
      } else if (r->left) {
        r->right = new TreeNode (v);
        return r->val;
      } else {
        r->left = new TreeNode (v);
        return r->val;
      }
    }
    return -1;  // dummy
  }

  TreeNode* get_root() {
    return root_;
  }
 private:
  TreeNode* root_;
  queue<TreeNode*> q_;
};

int main() {
  Solution s;
  
  return 0;
}
