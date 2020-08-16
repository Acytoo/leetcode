#include <iostream>
#include <sstream>
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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    int min_x = INT_MAX, max_x = INT_MIN;
    map<pair<int, int>, set<int>> h;
    traverse(root, 0, 0, h, min_x, max_x);
    vector<vector<int>> res(max_x - min_x + 1);
    for (const auto& m : h) {
      int x = m.first.second - min_x;
      res[x].insert(end(res[x]), begin(m.second), end(m.second));
    }
    return res;
  }
 private:
  void traverse(TreeNode *root, int x, int y,
                map<pair<int, int>, set<int>>& h,
                int &min_x, int &max_x) {
    if (!root) return;
    min_x = min(min_x, x);
    max_x = max(max_x, x);
    h[{y, x}].insert(root->val);
    traverse(root->left, x - 1, y + 1, h, min_x, max_x);
    traverse(root->right, x + 1, y + 1, h, min_x, max_x);
  }
};

int main() {
  Solution s;
  
  return 0;
}
