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
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return buildTree(preorder, 0, preorder.size()-1);
  }
 private:
  TreeNode* buildTree(vector<int>& pre, int l, int r) {
    if (l > r)
      return nullptr;
    TreeNode* cur = new TreeNode (pre[l]);
    int i=l+1;
    while (i <= r && pre[i] < pre[l])
      ++i;
    cur->left = buildTree(pre, l+1, i-1);
    cur->right = buildTree(pre, i, r);
    return cur;
  }
};

int main() {
  Solution s;
  
  return 0;
}
