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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    function<TreeNode*(int, int, int, int)> build =
        [&] (int li, int ri, int lp, int rp) -> TreeNode* {
          if (li > ri) return nullptr;
          if (li == ri) return new TreeNode(inorder[li]);
          TreeNode *root = new TreeNode(postorder[rp]);
          int idx = li;
          while (inorder[idx] != root->val) ++idx;
          // left child : [li, idx - 1], right child : [idx + 1, ri]
          // left child : [lp, lp + idx - li], right child : [lp + idx - li + 1, rp - 1]
          root->left = build(li, idx - 1, lp, lp + idx - li - 1);
          root->right = build(idx + 1, ri, lp + idx - li, rp - 1);
          return root;
        };
    return build(0, inorder.size() - 1, 0, inorder.size() - 1);
  }
};


class Solution_OLD {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> pos;
    int n = inorder.size()-1;
    for (int i=0; i<=n; ++i)
      pos[inorder[i]] = i;
    function<TreeNode*(int, int, int, int)> build =
        [&] (int is, int ie, int ps, int pe) -> TreeNode* {
          if (ps > pe)
            return nullptr;
          TreeNode* cur = new TreeNode (postorder[pe]);
          int im = pos[postorder[pe]];
          int pm = ps + im - is;
          cur->left = build(is, im-1, ps, pm-1);
          cur->right = build(im+1, ie, pm, pe-1);
          return cur;
        };
    return build(0, n, 0, n);
  }
};

int main() {
  Solution s;
  
  return 0;
}
