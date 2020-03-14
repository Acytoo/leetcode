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
  string smallestFromLeaf(TreeNode* root) {
    vector<string> strs;
    string cur_str = "";
    traversal(root, cur_str, strs);
    // sort(strs.begin(), strs.end());
    return *min_element(strs.begin(), strs.end());
  }
 private:
  void traversal(TreeNode* cur, string cur_str, vector<string>& strs) {
    cur_str += (char)('a'+cur->val);
    if (!cur->left && !cur->right) {
      // cur_str += (char)('a'+cur->val);
      reverse(cur_str.begin(), cur_str.end());
      strs.push_back(cur_str);
    }
    if (cur->left)
      traversal(cur->left, cur_str, strs);
    if (cur->right)
      traversal(cur->right, cur_str, strs);
  }
};

int main() {
  Solution s;
  
  return 0;
}
