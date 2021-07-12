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
// From huahua
class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() { }

  void addNum(int num) {
    if (l_.empty() || num <= l_.top())
      l_.push(num);
    else
      r_.push(num);

    if (l_.size() < r_.size()) {
      l_.push(r_.top());
      r_.pop();
    } else if (l_.size() - r_.size() == 2) {
      r_.push(l_.top());
      l_.pop();
    }
  }

  double findMedian() {
    if (l_.size() > r_.size())
      return static_cast<double>(l_.top());
    return static_cast<double>(l_.top() + r_.top()) / 2.0;
  }
 private:
  priority_queue<int, vector<int>, less<int>> l_;
  priority_queue<int, vector<int>, greater<int>> r_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  Solution s;
  
  return 0;
}
