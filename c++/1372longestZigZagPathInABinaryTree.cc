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
  int longestZigZag(TreeNode *root) {
    function<tuple<int, int, int>(TreeNode*)> zigzag =
        [&zigzag] (TreeNode *cur) -> tuple<int, int, int> {  // tuple of {left, right, max}
      if (!cur) return {-1, -1, -1};
      auto [ll, lr, lm] = zigzag(cur->left);
      auto [rl, rr, rm] = zigzag(cur->right);
      const int l = lr + 1, r = rl + 1;
      return {l, r, max({l, r, lm, rm})};
    };
    return get<2>(zigzag(root));
  }
};

int main() {
  Solution s;
  
  return 0;
}
