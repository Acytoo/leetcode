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
// 这种方法竟然通过了， 而且12ms, 比99.66%的算法跑得快？？？
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    return nums[--k];
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
