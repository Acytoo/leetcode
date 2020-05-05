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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From Huahua
class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    ++m_[start];
    --m_[end];
    int count = 0;
    for (const auto &kv: m_) {
      count += kv.second;
      if (count == 3) {
        --m_[start];
        ++m_[end];
        return false;
      }
      if (end < kv.first) break;
    }
    return true;
  }
 private:
  map<int, int> m_;
};

class MyCalendarTwo1 {
 public:
  MyCalendarTwo1() {}

  bool book(int start, int end) {
    for (const auto &kv: b2_)
      if (max(start, kv.first) < min(end, kv.second)) return false;
    for (const auto &kv: b1_) {
      int s = max(start, kv.first),
          e = min(end, kv.second);
      if (s < e) b2_.emplace_back(s, e);
    }
    b1_.emplace_back(start, end);
    return true;
  }
 private:
  vector<pair<int, int>> b1_, b2_;  // if double booking, make it b2
};

int main() {
  Solution s;
  
  return 0;
}
