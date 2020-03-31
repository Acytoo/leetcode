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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int N) {
    if (N & 1 == 0) return {};
    if (N == 1) return {new TreeNode (0)};
    vector<TreeNode*> res;
    for (int i=1; i<N; i+=2) {
      for (const auto& l: allPossibleFBT(i))
        for (const auto& r: allPossibleFBT(N - i - 1)) {
          TreeNode* cur = new TreeNode (0);
          cur->left = l;
          cur->right = r;
          res.push_back(cur);
        }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
