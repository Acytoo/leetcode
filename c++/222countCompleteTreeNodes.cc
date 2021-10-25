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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = 0, rh = 0;
    TreeNode *l = root, *r = root;
    while (l) {
      ++lh;
      l = l->left;
    }
    while (r) {
      ++rh;
      r = r->right;
    }
    if (lh == rh) return pow(2, lh) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

class Solution_On {
 public:
  int countNodes(TreeNode* root) {
    return root? 1+countNodes(root->left)+countNodes(root->right): 0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
