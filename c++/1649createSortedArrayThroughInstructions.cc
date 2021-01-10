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
  // From huahua, Fenwick tree
 public:
  int createSortedArray(vector<int>& instructions) {
    constexpr int kMod = 1e9 + 7;
    const int n = instructions.size();
    FenwickTree tree(1e5);
    long res = 0;
    for (int i = 0; i < n; ++i) {
      int lt = tree.query(instructions[i] - 1);
      int gt = i - tree.query(instructions[i]);
      res += min(lt, gt);
      tree.update(instructions[i], 1);
    }
    return res % kMod;
  }

 private:
  class FenwickTree {
   public:
    FenwickTree(int n): sums_(n + 1, 0) {}

    void update(int i, int delta) {
      const int n = sums_.size();
      while (i < n) {
        sums_[i] += delta;
        i += lowbit(i);
      }
    }

    int query(int i) const {
      int res = 0;
      while (i > 0) {
        res += sums_[i];
        i -= lowbit(i);
      }
      return res;
    }

   private:
    static inline int lowbit(const int x) { return x & (-x); }
    vector<int> sums_;
  };
};


int main() {
  Solution s;
  
  return 0;
}
