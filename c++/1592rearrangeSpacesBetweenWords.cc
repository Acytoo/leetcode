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
  string reorderSpaces(string text) {
    int space = 0;
    bool hasLetter = false;
    string cur, res;
    deque<string> dq;
    for (const char c: text)
      if (c == ' ') {
        if (hasLetter) {
          dq.push_back(cur);
          cur.clear();
          hasLetter = false;
        }
        ++space;
      } else {
        hasLetter = true;
        cur += c;
      }
    if (hasLetter) {
      dq.push_back(cur);
    }
    const int letter = dq.size();
    if (letter == 1) {
      res += dq.front();
      res += string (static_cast<int>(text.size() - res.size()), ' ');
      return res;
    }
    int n = letter - 1, each_sep = space / n;
    string sep(each_sep, ' ');
    while (--n >= 0) {
      res += dq.front(); dq.pop_front();
      res += sep;
    }
    res += dq.front();
    res += string (static_cast<int>(text.size() - res.size()), ' ');
    return res;
  }
};

int main() {
  Solution s;
  string a = "this is     sth";
  cout << s.reorderSpaces(a) << endl;
  return 0;
}
