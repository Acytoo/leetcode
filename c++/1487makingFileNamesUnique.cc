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
// input: ["wano(2)","wano(2)","wano(2)","wano(2)"]
// output: ["wano(2)","wano(2)(1)","wano(2)(2)","wano(2)(3)"]
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // 136 ms, just change count to find
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> m;
    vector<string> res;
    res.reserve(names.size());
    for (string &name : names) {
      if (m.find(name) == m.end()) {
        m.emplace(name, 1);
        res.emplace_back(move(name));
        continue;
      }
      int suffix = m[name];
      string new_name = name + '(' + to_string(suffix) + ')';
      while (m.count(new_name)) new_name = name + '(' + to_string(++suffix) + ')';
      m[name] = ++suffix;
      m.emplace(new_name, 1);
      res.emplace_back(move(new_name));
    }
    return res;
  }
};

class Solution_count {  // 260 ms
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> m;
    vector<string> res;
    res.reserve(names.size());
    for (string &name : names) {
      if (m.count(name) == 0) {
        m.emplace(name, 1);
        res.emplace_back(move(name));
        continue;
      }
      int suffix = m[name];
      string new_name = name + '(' + to_string(suffix) + ')';
      while (m.count(new_name)) new_name = name + '(' + to_string(++suffix) + ')';
      m[name] = ++suffix;
      m.emplace(new_name, 1);
      res.emplace_back(move(new_name));
    }
    return res;
  }
};

class Solution_same_as_count {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> m;
    vector<string> res;
    res.reserve(names.size());
    for (string &name: names) {
      if (m.count(name) == 0) {
        m[name] = 1;
        res.emplace_back(move(name));
        continue;
      }
      int i = m[name];
      string new_name = name + "(" + to_string(i) + ")";
      while (m.count(new_name) != 0) new_name = name + "(" + to_string(++i) + ")";
      m[name] = ++i;
      m[new_name] = 1;
      res.emplace_back(new_name);
    }
    return res;
  }
};

class Solution_TLE {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_set<string> s;
    vector<string> res;
    for (string &name: names) {
      if (s.count(name) == 0) {
        s.insert(name);
        res.emplace_back(move(name));
        continue;
      }
      int i = 1;
      string new_name = name + "(" + to_string(i) + ")";
      while (s.count(new_name) == 1) {
        ++i;
        new_name = name + "(" + to_string(i) + ")";
      }
      s.insert(new_name);
      res.emplace_back(move(new_name));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
