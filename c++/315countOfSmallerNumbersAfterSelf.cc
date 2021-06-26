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
// From huahua, Fenwick Tree
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    set<int> sorted(nums.begin(), nums.end());
    unordered_map<int, int> ranks;
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;

    vector<int> res;
    FenWickTree tree (ranks.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
      res.push_back(tree.query(ranks[nums[i]] - 1));
      tree.update(ranks[nums[i]], 1);
    }
    reverse(res.begin(), res.end());
    return res;
  }
 private:
  class FenWickTree {
   public:
    FenWickTree(int n): sums_(n + 1) {};

    void update(int i, int delta) {
      const int n = sums_.size();
      while (i < n) {
        sums_[i] += delta;
        i += lowbit(i);
      }
    }

    int query(int i) const {
      int sum = 0;
      while (i > 0) {
        sum += sums_[i];
        i -= lowbit(i);
      }
      return sum;
    }

   private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
  };
};


// From huahua, Binary search tree
class Solution_TLE {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> res{0};
    reverse(nums.begin(), nums.end());
    unique_ptr<BSTNode> root (new BSTNode(nums[0]));
    for (int i = 1, n = nums.size(); i < n; ++i)
      res.push_back(insert(root.get(), nums[i]));
    reverse(res.begin(), res.end());
    return res;
  }

 private:
  class BSTNode {
   public:
    int val, left_count, count;
    BSTNode *left, *right;

    BSTNode(int val): val(val), count(1), left_count(0), left(nullptr), right(nullptr) {}

    ~BSTNode() { delete left; delete right; }

    int less_or_equal() const { return count + left_count; }
  };

  int insert(BSTNode *cur, int val) {
    if (cur->val == val) {
      ++cur->count;
      return cur->left_count;
    } else if (cur->val < val) {
      if (cur->right == nullptr) {
        cur->right = new BSTNode(val);
        return cur->less_or_equal();
      }
      return cur->less_or_equal() + insert(cur->right, val);
    } else {  // val < cur->val
      ++cur->left_count;
      if (cur->left == nullptr) {
        cur->left = new BSTNode(val);
        return 0;
      }
      return insert(cur->left, val);
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
