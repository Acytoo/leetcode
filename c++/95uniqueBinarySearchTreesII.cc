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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    function<vector<TreeNode*>(int, int)> build =
        [&] (const int l, const int r) -> vector<TreeNode*> {
          if (l > r) return {nullptr};
          vector<TreeNode*> res;
          for (int i = l; i <= r; ++i)
            for (TreeNode *left: build(l, i - 1))
              for (TreeNode *right: build(i + 1, r)) {
                TreeNode *cur = new TreeNode(i, left, right);
                res.emplace_back(move(cur));
              }
          return res;
        };
    return build(1, n);
  }
};

int main() {
  Solution s;
  
  return 0;
}
