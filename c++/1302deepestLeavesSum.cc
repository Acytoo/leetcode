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
  int deepestLeavesSum(TreeNode* root) {
    deque<TreeNode*> dq;
    vector<int> leaves;
    dq.push_back(root);
    while (!dq.empty()) {
      leaves.clear();
      int num = dq.size();
      while (num) {
        TreeNode *cur = dq.back(); dq.pop_back();
        leaves.push_back(cur->val);
        if (cur->left) dq.push_front(cur->left);
        if (cur->right) dq.push_front(cur->right);
        --num;
      }
    }
    return accumulate(leaves.begin(), leaves.end(), 0);
  }
};

class Solution1 {
 public:
  int deepestLeavesSum(TreeNode* root) {
    vector<int> leaves;
    int max_depth = 0;
    function<void(int, TreeNode*)> helper = [&] (int depth, TreeNode *cur) {
      if (!cur) return;
      if (depth > max_depth) {
        max_depth = depth;
        leaves.clear();
        leaves.push_back(cur->val);
      } else if (depth == max_depth) {
        leaves.push_back(cur->val);
      }
      helper(depth + 1, cur->left);
      helper(depth + 1, cur->right);
    };
    helper(0, root);
    return accumulate(leaves.begin(), leaves.end(), 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
