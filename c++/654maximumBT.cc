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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return treeBuilder(nums, nums.begin(), nums.end());
  }
 private:
  TreeNode* treeBuilder(vector<int>& nums, vector<int>::iterator l, vector<int>::iterator r) {
    if (l >= r)
      return nullptr;
    auto it = max_element(l, r);
    TreeNode* cur = new TreeNode (*it);
    cur->left = treeBuilder(nums, l, it);
    cur->right = treeBuilder(nums, it+1, r);
    return cur;
  }
};

int main() {
  Solution s;
  
  return 0;
}
