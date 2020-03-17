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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> counts;
    vector<TreeNode*> res;
    serialize(root, res, counts);
    return res;
  }
 private:
  string serialize(TreeNode* cur, vector<TreeNode*>& res, unordered_map<string, int>& counts) {
    if (!cur)
      return "#";
    string key = to_string(cur->val) + ","
                 + serialize(cur->left, res, counts) + ","
                 + serialize(cur->right, res, counts);
    if (++counts[key] == 2)
      res.push_back(cur);
    return key;
  }
};

int main() {
  Solution s;
  
  return 0;
}
