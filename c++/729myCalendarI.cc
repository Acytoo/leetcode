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
class MyCalendar {
 public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto it = booked_.lower_bound(start);
    if (it != booked_.end() && it->first < end) return false;
    if (it != booked_.begin() && start < (--it)->second) return false;
    booked_[start] = end;
    return true;
  }
 private:
  map<int, int> booked_;
};

class MyCalendar1 {
 public:
  MyCalendar1() {
    table_.clear();
  }

  bool book(int start, int end) {
    int i = table_.size();
    while (--i >= 0)
      if ((table_[i].first < end && end <= table_[i].second) ||
          (table_[i].first <= start && start < table_[i].second) ||
          (start <= table_[i].first && table_[i].second < end))
        break;

    if (i != -1) return false;
    table_.emplace_back(start, end);
    return true;
  }
 private:
  vector<pair<int, int>> table_;
};


int main() {
  MyCalendar1 m;
  
  return 0;
}
