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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    levelOrder(root, res, 0);
    for (int i=1, stop=res.size(); i<stop; i+=2)
      reverse(res[i].begin(), res[i].end());
    return res;
  }
 private:
  void levelOrder(TreeNode* cur, vector<vector<int>>& res, int level) {
    if (!cur)
      return ;
    if (res.size() <= level)
      res.push_back({});
    res[level].push_back(cur->val);
    levelOrder(cur->left, res, ++level);
    levelOrder(cur->right, res, level);
  }
};

int main() {
  Solution s;
  
  return 0;
}
