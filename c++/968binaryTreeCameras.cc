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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua greedy + recursion
class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    enum class State: char { UNMONITORED, MONITORED, CAMERA };
    int res = 0;

    function<State(TreeNode*)> helper = [&] (TreeNode *cur) -> State {
      if (!cur) return State::MONITORED;
      State l = helper(cur->left),
            r = helper(cur->right);
      if (l == State::UNMONITORED || r == State::UNMONITORED) {
        ++res;
        return State::CAMERA;
      }
      if (l == State::CAMERA || r == State::CAMERA)
        return State::MONITORED;
      return State::UNMONITORED;
    };

    if (helper(root) == State::UNMONITORED) ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
