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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class NumArray {
  // Fenwick Tree
 public:
  NumArray(vector<int>& nums): tree_(nums.size()), nums_(move(nums)) {
    for (int i = 0, n = nums_.size(); i < n; ++i) tree_.update(i + 1, nums_[i]);
  }

  void update(int index, int val) {
    tree_.update(index + 1, val - nums_[index]);
    nums_[index] = val;
  }

  int sumRange(int left, int right) {
    return tree_.query(right + 1) - tree_.query(left);
  }
 private:
  class FenwickTree {
   public:
    FenwickTree(int n): sums_(n + 1, 0) { }

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
    vector<int> sums_;
    static inline int lowbit(int x) { return x & (-x); }
  };
  FenwickTree tree_;
  vector<int> nums_;
};

class NumArray1 {
  // Blocks
 public:
  NumArray(vector<int>& nums) {
    if (nums.empty()) return ;
    const int data_size = nums.size();
    len_ = ceil(sqrt(data_size));  // also number of blocks
    block_ = vector<int> (len_);
    for (int i = 0; i < data_size; ++i)
      block_[i / len_] += nums[i];
    data_ = nums;
  }

  void update(int index, int val) {
    const int block_idx = index / len_;
    block_[block_idx] += val - data_[index];
    data_[index] = val;
  }

  int sumRange(int left, int right) {
    int res = 0;
    int start = left / len_, end = right / len_;
    if (start == end) {
      for (int i = left; i <= right; ++i)
        res += data_[i];
      return res;
    }
    for (int i = left, stop = (start + 1) * len_; i < stop; ++i)
      res += data_[i];
    for (int i = start + 1; i < end; ++i)
      res += block_[i];
    for (int i = end * len_; i <= right; ++i)
      res += data_[i];
    return res;
  }
 private:
  vector<int> data_, block_;
  int len_;
};


class NumArray_TLE {  // AC at 04/19/2020 08:13 and TLE at 06/18/2021
 public:
  NumArray(vector<int>& nums) {
    const int n = nums.size();
    if (n == 0) return ;
    nums_ = nums;
    sums_.resize(n);
    sums_[0] = nums_[0];
    for (int i=1; i<n; ++i)
      sums_[i] = nums_[i] + sums_[i-1];
  }

  void update(int i, int val) {
    int bk = nums_[i];
    nums_[i] = val;
    for (int j=i, stop=sums_.size(); j<stop; ++j)
      sums_[j] = sums_[j] - bk + val;
  }

  int sumRange(int i, int j) {
    if (i == 0)
      return sums_[j];
    return sums_[j] - sums_[--i];
  }
 private:
  vector<int> nums_, sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
  Solution s;
  
  return 0;
}
