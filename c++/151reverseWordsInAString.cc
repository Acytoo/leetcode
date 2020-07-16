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
  string reverseWords(string s) {
    stack<string> stk;
    stringstream ss (s);
    string cur = "";
    while (ss >> cur) stk.push(cur);
    if (stk.empty())
      return "";
    else
      stk.pop();
    while (!stk.empty()) {
      cur.push_back(' ');
      cur += stk.top();
      stk.pop();
    }
    return cur;
  }
};

class Solution1 {
 public:
  string reverseWords(string s) {
    stack<string> stk;
    string cur = "";
    for (const char c: s)
      if (c == ' ') {
        if (!cur.empty()) {
          stk.push(cur);
          cur.clear();
        }
      } else {
        cur += c;
      }
    if (cur.empty()) {
      if (stk.empty()) return "";
      cur = stk.top();
      stk.pop();
    }
    while (!stk.empty()) {
      cur += ' ';
      cur += stk.top();
      stk.pop();
    }
    return cur;
  }
};

int main() {
  Solution s;
  
  return 0;
}
