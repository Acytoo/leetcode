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
  int minDepth(TreeNode* root) {
    if (!root)
      return 0;
    if (!root->left && !root->right)
      return 1;
    int l_height = root->left? minDepth(root->left): INT_MAX;
    int r_height = root->right? minDepth(root->right): INT_MAX;
    return min(l_height, r_height) + 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
