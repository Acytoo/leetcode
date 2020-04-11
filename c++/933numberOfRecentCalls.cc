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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class RecentCounter {
 public:
  RecentCounter() {
  }

  int ping(int t) {
    int start_time = t - 3000;
    while (!q_.empty()) {
      if (q_.front() >= start_time) break;
      q_.pop();
    }
    q_.push(t);
    return q_.size();
  }
 private:
  queue<int> q_;
};


int main() {
  Solution s;
  
  return 0;
}
