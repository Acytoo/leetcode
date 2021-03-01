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
class FreqStack {
 public:
  FreqStack() {
  }

  void push(int x) {
    auto it = freq_.find(x);
    if (it == freq_.end())
      it = freq_.emplace(x, 0).first;
    int freq = ++(it->second);
    if (stks_.size() < freq) stks_.push_back({});
    stks_[freq - 1].push(x);
  }

  int pop() {
    const int res = stks_.back().top();
    stks_.back().pop();
    if (stks_.back().empty()) stks_.pop_back();
    auto it = freq_.find(res);
    if (it->second == 1)
      freq_.erase(res);
    else
      --(it->second);
    return res;
  }
 private:
  unordered_map<int, int> freq_;  // val -> freq
  vector<stack<int>> stks_;       // vector of freq-stack
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main() {
  Solution s;
  
  return 0;
}
