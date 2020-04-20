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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    flatter(nestedList);
    n_ = data_.size();
    i_ = 0;
  }

  int next() {
    return data_[i_++];
  }

  bool hasNext() const {
    return i_ < n_;
  }
 private:
  vector<int> data_;
  int n_, i_;

  void flatter(const vector<NestedInteger> &nestedList) {
    if (nestedList.empty()) return ;

    for (const NestedInteger &nint: nestedList)
      if (nint.isInteger())
        data_.push_back(nint.getInteger());
      else
        flatter(nint.getList());
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  // Solution s;
  
  return 0;
}
