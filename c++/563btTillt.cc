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
  int findTilt(TreeNode* root) {
    int res = 0;
    function<int(TreeNode*)> summ = [&](TreeNode* cur) {
                                      if (!cur)
                                        return 0;
                                      int sum_left = summ(cur->left);
                                      int sum_right = summ(cur->right);
                                      res += abs(sum_left - sum_right);
                                      return sum_left + sum_right + cur->val;
                                    };
    summ(root);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
