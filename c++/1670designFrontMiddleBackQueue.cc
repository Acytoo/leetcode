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

// From huahua
class FrontMiddleBackQueue {
 public:
  FrontMiddleBackQueue() { }

  void pushFront(int val) {
    q_.push_front(val);
    updateMid(odd()? 0: -1);
  }

  void pushMiddle(int val) {
    if (q_.empty())
      q_.push_back(val);
    else
      q_.insert(odd()? mid_: next(mid_), val);
      updateMid(odd()? 1: -1);
  }

  void pushBack(int val) {
    q_.push_back(val);
    updateMid(odd()? 1: 0);
  }

  int popFront() {
    if (q_.empty()) return -1;
    int val = q_.front(); q_.pop_front();
    updateMid(odd()? 1: 0);
    return val;
  }

  int popMiddle() {
    if (q_.empty()) return -1;
    int val = *mid_;
    mid_ = q_.erase(mid_);
    updateMid(odd()? 0: -1);
    return val;
  }

  int popBack() {
    if (q_.empty()) return -1;
    int val = q_.back(); q_.pop_back();
    updateMid(odd()? 0: -1);
    return val;
  }
 private:
  void updateMid(int delta) {
    if (q_.size() <= 1) {
      mid_ = q_.begin();
    } else {
      if (delta > 0) ++mid_;
      else if (delta < 0) --mid_;
    }
  }

  bool odd() const { return q_.size() & 1; }

  list<int> q_;
  list<int>::iterator mid_;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main() {
  Solution s;
  
  return 0;
}
