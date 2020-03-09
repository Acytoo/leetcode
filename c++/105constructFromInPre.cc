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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // 记住inorder中的每一个节点的位置
    unordered_map<int, int> pos;
    for (int i=0, stop=inorder.size(); i<stop; ++i)
      pos[inorder[i]] = i;

    function<TreeNode*(int, int, int, int)> build =
        [&] (int ps, int pe, int is, int ie) -> TreeNode* {
          if (ps > pe)
            return nullptr;
          TreeNode* cur = new TreeNode (preorder[ps]);
          int im = pos[preorder[ps]];
          int pm = ps + im - is;
          cur->left = build(ps+1, pm, is, im-1);
          cur->right = build(pm+1, pe, im+1, ie);
          return cur;
        };
    int n = inorder.size()-1;
    TreeNode* root = build(0, n, 0, n);
    return root;
  }
};

int main() {
  Solution s;
  
  return 0;
}
