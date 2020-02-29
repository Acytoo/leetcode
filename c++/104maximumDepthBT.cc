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
// recursion
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root)
      return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
