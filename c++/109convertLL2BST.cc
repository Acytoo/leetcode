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
  TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }
    int l = 0, r = nums.size()-1;
    TreeNode* root = buildTree(nums, l, r);
    return root;
  }
 private:
  TreeNode* buildTree(const vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    int m = (l + r) >> 1;
    TreeNode* cur = new TreeNode (nums[m]);
    cur->left = buildTree(nums, l, m-1);
    cur->right = buildTree(nums, m+1, r);
    return cur;
  }
};

int main() {
  Solution s;
  
  return 0;
}
