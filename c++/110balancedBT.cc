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
  bool isBalanced(TreeNode* root) {
    if (!root)
      return true;
    int l_height = get_height(root->left);
    int r_height = get_height(root->right);
    return (abs(l_height-r_height)<=1) && isBalanced(root->left) && isBalanced(root->right);
  }
 private:
  int get_height(TreeNode* cur) {
    if (!cur)
      return 0;
    return max(get_height(cur->left), get_height(cur->right))+1;
  }
};


int main() {
  Solution s;
  
  return 0;
}
