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
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    int l = 0, r = nums.size()-1;
    while (l < r) {
      int sum = nums[l] + nums[r];
      if (sum == k)
        return true;
      if (sum < k)
        ++l;
      else
        --r;
    }
    return false;
  }
 private:
  void inorder(TreeNode* cur, vector<int>& nums) {
    if (!cur)
      return ;
    inorder(cur->left, nums);
    nums.push_back(cur->val);
    inorder(cur->right, nums);
  }
};


int main() {
  Solution s;
  
  return 0;
}
