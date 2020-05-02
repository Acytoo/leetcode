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
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res (n);
    stack<int> s;
    int last_id = 0, last_stamp = 0;
    for (const auto &log: logs) {
      int id = 0, timestamp = 0;
      char event[6];
      sscanf(log.c_str(), "%d:%[a-z]:%d", &id, event, &timestamp);
      if (event[0] == 's') {  // "start"
        if (!s.empty()) res[s.top()] += timestamp - last_stamp;
        s.push(id);
        last_stamp = timestamp;
      } else {  // end
        res[s.top()] += timestamp - last_stamp + 1;
        s.pop();
        last_stamp = timestamp + 1;
      }
    }
    return res;
  }
};


class Solution1 {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res (n);
    stack<int> s;
    int last_id = stoi(logs[0].substr(0, logs[0].find_first_of(':'))),
     last_stamp = stoi(logs[0].substr(logs[0].find_last_of(':')+1));

    for (auto &log: logs) {
      int p1 = log.find_first_of(':'), p2 = log.find_last_of(':');
      int id = stoi(log.substr(0, p1));
      string event = log.substr(p1+1, 3);
      int timestamp = stoi(log.substr(p2+1));

      if (event == "sta") {
        if (!s.empty()) res[s.top()] += timestamp - last_stamp;
        // res[last_id] += timestamp - last_stamp;
        s.push(id);
        last_stamp = timestamp;
        // last_id = id;
      } else {  // "end"
        res[s.top()] += timestamp - last_stamp + 1;
        s.pop();
        // last_id = s.top();
        last_stamp = timestamp + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
