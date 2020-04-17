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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if (!root) return nullptr;
    int l = getDepth(root->left), r = getDepth(root->right);
    if (l < r)
      return lcaDeepestLeaves(root->right);
    else if (r < l)
      return lcaDeepestLeaves(root->left);
    else
      return root;
  }
 private:
  unordered_map<TreeNode*, int> m_;  // TreeNode*, depth
  int getDepth(TreeNode *cur) {
    if (!cur) return 0;
    if (m_.find(cur) != m_.end()) return m_[cur];
    return m_[cur] = max(getDepth(cur->left), getDepth(cur->right)) + 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
