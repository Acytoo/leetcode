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
class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    function<TreeNode*(int, int, int, int)> build =
        [&] (int prel, int prer, int postl, int postr) -> TreeNode* {
          if (prel == prer) return nullptr;
          TreeNode *cur = new TreeNode (pre[prel]);
          ++prel; --postr;
          if (prel == prer) return cur;
          int lpostr = find(post.begin() + postl, post.begin() + postr, pre[prel]) - post.begin() + 1;
          int lprer = prel + lpostr - postl;
          cur->left = build(prel, lprer, postl, lpostr);
          cur->right = build(lprer, prer, lpostr, postr);
          return cur;
        };
    return build(0, pre.size(), 0, post.size());
  }
};

int main() {
  Solution s;
  
  return 0;
}
