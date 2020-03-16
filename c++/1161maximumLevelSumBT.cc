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
  int maxLevelSum(TreeNode* root) {
    vector<int> sums;
    getSum(root, sums, 0);
    return max_element(sums.begin(), sums.end()) - sums.begin() + 1;
  }
 private:
  void getSum(TreeNode* cur, vector<int>& sums, int depth) {
    if (!cur)
      return ;
    if (sums.size() <= depth)
      sums.push_back(cur->val);
    else
      sums[depth] += cur->val;
    getSum(cur->left, sums, ++depth);
    getSum(cur->right, sums, depth);
  }
};

int main() {
  Solution s;

  return 0;
}
