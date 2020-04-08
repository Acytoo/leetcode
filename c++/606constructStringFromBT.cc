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
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string tree2str(TreeNode* t) {
    string res = "";
    if (!t) return res;
    function<void(TreeNode*)> helper =
        [&] (TreeNode* cur) {
          if (!cur) return ;
          res += "(" + to_string(cur->val);
          if (!cur->left && cur->right) res += "()";
          helper(cur->left);
          helper(cur->right);
          res += ")";
        };
    helper(t);
    return string(res.begin()+1, res.end()-1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
