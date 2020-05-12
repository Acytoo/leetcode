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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    const int n = arr.size() - 1;
    function<bool(TreeNode*, int)> valid =
        [&] (TreeNode *cur, int idx) {
          if (!cur) return false;
          if (idx == n) return (cur->val==arr.back() && !cur->left && !cur->right);
          if (arr[idx] != cur->val) return false;
          return valid(cur->left, ++idx) || valid(cur->right, idx);
        };

    return valid(root, 0);
  }
};

// 1 <= arr.length <= 5000
// 0 <= arr[i] <= 9
class Solution_same {
 public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    if (!root) return false;
    const int n = arr.size() - 1;
    function<bool(TreeNode*, int)> valid =
        [&] (TreeNode *cur, int idx) {
          if (!cur) return false;

          if (idx == n)
            if (cur->val == arr.back() &&
                !cur->left && !cur->right) return true;
            else
              return false;

          if (arr[idx] != cur->val) return false;
          return valid(cur->left, idx+1) || valid(cur->right, idx+1);
        };
    return valid(root, 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
