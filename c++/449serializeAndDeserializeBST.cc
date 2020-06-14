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

// leetcode 606, 297, 1028
// preorder
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "";
    string res = "";
    function<void(TreeNode*)> preorder =
        [&] (const TreeNode* cur) {
          if (!cur) {
            res += "-,";
            return ;
          }
          res += to_string(cur->val) + ",";
          preorder(cur->left);
          preorder(cur->right);
        };
    preorder(root);
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    const int n = data.size();
    int idx = 0;
    function<TreeNode*(void)> build =
        [&] () ->TreeNode* {
          if (idx >= n || data[idx] == '-') {
            idx += 2;
            return nullptr;
          }
          int val = 0;
          while (data[idx] != ',')
            val = val * 10 + (data[idx++] - '0');
          ++idx;
          TreeNode *cur = new TreeNode (val);
          cur->left = build();
          cur->right = build();
          return cur;
        };
    return build();
  }
};

int main() {
  Solution s;
  
  return 0;
}
