#include <iostream>
#include <sstream>
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
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    function<TreeNode*(TreeNode*)> helper = [&] (TreeNode *cur) -> TreeNode* {
      if (!cur) return nullptr;
      if (!cur->left && !cur->right) {
        res.back().emplace_back(cur->val);
        return nullptr;
      }
      cur->left = helper(cur->left);
      cur->right = helper(cur->right);
      return cur;
    };
    while(root) {
      res.emplace_back(vector<int>());
      root = helper(root);
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
