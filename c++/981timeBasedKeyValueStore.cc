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
class TimeMap {
 public:
  /** Initialize your data structure here. */
  TimeMap() {

  }

  void set(string key, string value, int timestamp) {
    m_[key].emplace(timestamp, move(value));
  }

  string get(string key, int timestamp) {
    auto m = m_.find(key);
    if (m == m_.end()) return "";
    auto it = m->second.upper_bound(timestamp);
    if (it == (m->second).begin()) return "";
    return prev(it)->second;
  }
 private:
  unordered_map<string, map<int, string>> m_;  // key --> (timestamp --> value)
};

int main() {
  Solution s;
  
  return 0;
}
