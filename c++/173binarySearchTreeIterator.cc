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
class BSTIterator {
 public:
  BSTIterator(TreeNode* root): cur_(root){ }

  int next() {
    while (cur_) {
      s_.push(cur_);
      cur_ = cur_->left;
    }
    cur_ = s_.top(); s_.pop();
    int res = cur_->val;
    cur_ = cur_->right;
    return res;
  }

  bool hasNext() {
    return !s_.empty() || cur_;
  }
 private:
  stack<TreeNode*> s_;
  TreeNode *cur_;
};

int main() {
  Solution s;
  
  return 0;
}
