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
class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    // level order traversal, and left first, right second
    queue<TreeNode*> q;
    q.push(root);
    bool last_one = false;
    while (!q.empty()) {
      int t = q.size();
      while (t--) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          if (last_one)
            return false;
          q.push(cur->left);
          q.push(cur->right);
        } else {
          last_one = true;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
