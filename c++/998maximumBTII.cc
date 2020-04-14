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
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (!root) return new TreeNode (val);
    if (root->val < val) {
      TreeNode *res = new TreeNode(val);
      val->left = root;
      return res;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
