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
class Logger {
 public:
  Logger() { }

  bool shouldPrintMessage(int timestamp, string message) {
    if (m_.count(message) && m_[message] > timestamp) return false;
    m_[message] = timestamp + 10;
    return true;
  }
 private:
  unordered_map<string_view, int> m_;
};

class Logger_OLD {
 public:
  Logger() {
    m_.clear();
  }

  bool shouldPrintMessage(int timestamp, string message) {
    if (m_.find(message) == m_.end()) {
      m_.emplace(message, timestamp);
      return true;
    }
    if (timestamp - m_[message] < 10)
      return false;
    m_[message] = timestamp;
    return true;
  }
 private:
  unordered_map<string, int> m_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main() {
  Solution s;
  
  return 0;
}
