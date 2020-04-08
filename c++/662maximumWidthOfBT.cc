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
// Level order traversal
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    int res = 0;
    if (!root) return res;
    queue<pair<TreeNode*, int>> q;  // node -> position
    q.emplace(make_pair(root, 1));
    while (!q.empty()) {
      if (q.size() == 1) q.front().second = 1;
      int l = q.front().second, r = l, n = q.size();
      for (int i=0; i<n; ++i) {
        TreeNode *cur = q.front().first;
        r = q.front().second;
        q.pop();
        if (cur->left) q.emplace(make_pair(cur->left, r<<1));
        if (cur->right) q.emplace(make_pair(cur->right, (r<<1)+1));
      }
      res = max(res, r-l+1);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
