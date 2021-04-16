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
  string evaluate(string_view s, vector<vector<string>>& knowledge) {
    unordered_map<string_view, string> m;
    for (const auto &k : knowledge)
      m.emplace(k[0], k[1]);
    string res = "";
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      if (s[i] != '(') {
        res += s[i];
      } else {
        int r = i + 1;
        while (s[r] != ')') ++r;
        string_view key = s.substr(i + 1, r - i - 1);
        if (m.count(key) != 0)
          res += m[key];
        else
          res += '?';
        i = r;
      }
    }
    return res;
  }
};

class Solution1 {
 public:
  string evaluate(string_view s, vector<vector<string>>& knowledge) {
    unordered_map<string_view, string> m;
    for (const auto &k : knowledge)
      m.emplace(move(k[0]), move(k[1]));
    string res = "";
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      if (s[i] != '(') {
        res += s[i];
      } else {
        int r = i + 1;
        while (s[r] != ')') ++r;
        string_view key = s.substr(i + 1, r - i - 1);
        if (m.count(key) != 0)
          res += m[key];
        else
          res += '?';
        i = r;
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
