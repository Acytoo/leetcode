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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class CustomStack {
 public:
  CustomStack(int maxSize): max_size_(maxSize) { }

  void push(int x) {
    if (data_.size() == max_size_)
      return ;
    data_.push_back(x);
  }

  int pop() {
    if (data_.empty())
      return -1;
    int res = data_.back();
    data_.pop_back();
    return res;
  }

  void increment(int k, int val) {
    k = min(k, static_cast<int>(data_.size()));
    while (k-- > 0)
      data_[k] += val;
  }
 private:
  vector<int> data_;
  int max_size_;
};


int main() {
  Solution s;
  
  return 0;
}
