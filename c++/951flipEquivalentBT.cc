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
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if ((!root1 && root2) || (root1 && !root2)) return false;
    if (root1->val != root2->val) return false;
    bool keep = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right),
         flip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    return keep || flip;
  }
};

int main() {
  Solution s;
  
  return 0;
}
