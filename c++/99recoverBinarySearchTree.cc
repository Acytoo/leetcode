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
  void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *second = nullptr, *pre = nullptr;
    function<void(TreeNode*)> inorder = [&] (TreeNode *cur) {
      if (!cur) return;
      inorder(cur->left);
      if (pre && pre->val > cur->val) {
        if (!first) first = pre;
        second = cur;
      }
      pre = cur;
      inorder(cur->right);
    };
    inorder(root);
    swap(first->val, second->val);
  }
};

int main() {
  Solution s;
  
  return 0;
}
