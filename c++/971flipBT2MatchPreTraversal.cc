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
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> res;
    int idx = 0;
    function<void(TreeNode*)> preorder =
        [&] (TreeNode *cur) {
          if (!cur) return ;
          if (cur->val != voyage[idx]) {
            res = {-1};
            return ;
          }
          if (cur->left && cur->left->val!=voyage[idx+1]) {
            res.push_back(cur->val);
            swap(cur->left, cur->right);
          }
          ++idx;
          preorder(cur->left);
          preorder(cur->right);
        };
    preorder(root);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
