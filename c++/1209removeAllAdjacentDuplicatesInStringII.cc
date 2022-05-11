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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    deque<pair<char, int>> dq;
    dq.push_back(make_pair('*', 0));
    for (const char c : s)
      if (c != dq.back().first)
        dq.emplace_back(make_pair(c, 1));
      else if (++dq.back().second == k)
        dq.pop_back();
    string res;
    while (!dq.empty()) {
      res.append(dq.front().second, dq.front().first);
      dq.pop_front();
    }
    return res;
  }
};

class Solution_RUN_TIME_ERR {
 public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, char>> stk;
    stk.push(make_pair('*', 0));
    for (const char c : s)
      if (c != stk.top().first)
        stk.push(make_pair(c, 1));
      else if (++stk.top().second == k)
        stk.pop();
    string res = "";
    while (!stk.empty()) {
      res.append(stk.top().second, stk.top().first);
      stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

class Solution {
 public:
  // stack
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> stk {{'*', 0}};
    for (const char c: s)
      if (c != stk.back().first)
        stk.emplace_back(c, 1);
      else if (++stk.back().second == k)
        stk.pop_back();
    string res;
    for (const auto& i: stk)
      res.append(i.second, i.first);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
