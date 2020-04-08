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
  vector<vector<string>> printTree(TreeNode* root) {
    int h = getHeight(root);
    int w = (1<<h) - 1;
    vector<vector<string>> res (h, vector<string> (w));
    print(root, res, 0, 0, w-1);
    return res;
  }
 private:
  int getHeight(TreeNode *cur) {
    if (!cur) return 0;
    return max(getHeight(cur->left), getHeight(cur->right)) + 1;
  }

  void print(TreeNode *cur, vector<vector<string>> &res, int h, int l, int r) {
    if (!cur) return ;
    int m = (l+r) >> 1;
    res[h][m] = to_string(cur->val);
    print(cur->left, res, ++h, l, m-1);
    print(cur->right, res, h, m+1, r);
  }
};

int main() {
  Solution s;
  
  return 0;
}
