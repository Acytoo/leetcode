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
// not recursive
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root)
      return res;

    stack<pair<TreeNode*, bool>> s;  // TreeNode, visited(bool)
    s.push(make_pair(root, false));
    while (!s.empty()) {
      TreeNode* cur = s.top().first;
      bool visited = s.top().second;
      s.pop();
      if (!cur)
        continue;
      if (visited) {
        res.push_back(cur->val);
      } else {
        s.push(make_pair(cur, true));
        s.push(make_pair(cur->right, false));
        s.push(make_pair(cur->left, false));
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
