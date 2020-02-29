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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!t || !s)
      return false;

    if (same(s, t))
      return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
 private:
  bool same(TreeNode* s, TreeNode* t) {
    if (!s && !t)
      return true;
    if (!s || !t)
      return false;
    return (s->val == t->val) && same(s->left, t->left) && same(s->right, t->right);
  }
};

int main() {
  Solution s;
  
  return 0;
}
