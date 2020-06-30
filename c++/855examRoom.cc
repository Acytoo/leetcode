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
class ExamRoom {
 public:
  ExamRoom(int N): N_(N) { }

  int seat() {
    int p = 0, max_dist = s_.empty()? 0: *s_.begin();
    auto left = s_.begin(), right = left;
    while (left != s_.end()) {
      ++right;
      int l = *left, r = right == s_.end()? ((N_ - 1) << 1) - l: *right, d = (r - l) >> 1;
      if (d > max_dist) {
        max_dist = d;
        p = d + l;
      }
      left = right;
    }
    s_.insert(p);
    return p;
  }

  void leave(int p) {
    s_.erase(p);
  }
 private:
  const int N_;
  set<int> s_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() {
  Solution s;
  
  return 0;
}
