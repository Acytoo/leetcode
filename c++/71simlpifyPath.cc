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
class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> vec;
    string cur;
    path.push_back('/');
    for (int i = 0, n = path.size(); i < n; ++i) {
      if (path[i] == '/') {
        if (cur.empty()) continue;

        if (cur == "..") {
          if (!vec.empty()) vec.pop_back();
        } else if (cur != ".") {
          vec.push_back(cur);
        }
        cur.clear();
      } else {
        cur.push_back(path[i]);
      }
    }
    string res = "/";
    for (auto &t : vec) res += t + "/";
    if (res.size() > 1) res.pop_back();
    return res;
  }
};

class Solution1 {
 public:
  string simplifyPath(string path) {
    deque<string> dq;
    string cur = "";
    for (int i = 1, n = path.size(); i < n; ++i) {
      if (path[i] == '/') {
        if (!cur.empty()) {
          if (cur == "..") {
            if (!dq.empty())
              dq.pop_back();
          } else if (cur != ".") {
            dq.emplace_back(cur);
          }
          cur.clear();
        }
      } else {
        cur += path[i];
      }
    }
    if (!cur.empty()) {
      if (cur == "..") {
        if (!dq.empty()) dq.pop_back();
      } else if (cur != ".") {
        dq.emplace_back(move(cur));
      }
    }
    string res = "/";
    if (dq.empty()) return res;
    for (int i = 0, n = dq.size() - 1; i < n; ++i) {
      res += dq.front() + '/';
      dq.pop_front();
    }
    res += dq.front();
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
