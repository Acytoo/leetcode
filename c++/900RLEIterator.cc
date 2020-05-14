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
class RLEIterator {
 public:
  RLEIterator(vector<int>& A):idx_(0) {
    for (int i = 0, stop = A.size() >> 1; i < stop; ++i) {
      if (A[i << 1] == 0) continue;
      cnt_val_.emplace_back(A[i << 1], A[(i << 1) + 1]);
    }
    n_ = cnt_val_.size();
  }

  int next(int n) {
    int res = -1;
    if (idx_ >= n_) return res;

    while (idx_ < n_ && n >= cnt_val_[idx_].first) {
      n -= cnt_val_[idx_].first;
      res = cnt_val_[idx_].second;
      ++idx_;
    }
    if (idx_ >= n_ && n > 0) return -1;
    if (idx_ < n_ && n > 0) {
      cnt_val_[idx_].first -= n;
      res = cnt_val_[idx_].second;
    }

    return res;
  }
 private:
  vector<pair<int, int>> cnt_val_;
  int idx_, n_;
};

int main() {
  Solution s;
  
  return 0;
}
