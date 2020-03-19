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
#include <mutex>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> q;
    vector<double> res;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      double sum = .0;
      for (int i=0; i<n; ++i) {
        TreeNode* cur = q.front();
        q.pop();
        sum += cur->val;
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      res.push_back(sum / n);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
