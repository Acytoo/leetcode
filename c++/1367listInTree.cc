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
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!root)
      return false;
    return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
  }
 private:
  bool check(ListNode* head, TreeNode* cur) {
    if (!head)
      return true;
    if (!cur)
      return false;
    if (head->val != cur->val)
      return false;
    return check(head->next, cur->left) || check(head->next, cur->right);
  }
};

int main() {
  Solution s;
  
  return 0;
}
