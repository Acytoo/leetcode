z#include <iostream>
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

using namespace std;

// "00110011" => 6
// 111000 => 3
// 101 => 2

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int res = 0, cur = 1, i = s.size() - 1, pre = 0;
    while (i > 0) {
      if (s[i] == s[--i]) {
        ++cur;
      } else {
        res += min(cur, pre);
        pre = cur;
        cur = 1;
      }
    }
    return res + min(pre, cur);
  }
};


class Solution_OLD {
 public:
  int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, res = 0;
    int n = s.size()-1;
    while (n > 0) {
      if (s[n] == s[--n]) {
        ++cur;
      } else {
        res += min(pre, cur);
        pre = cur;
        cur = 1;
      }
    }
    return res+min(pre, cur);
  }
};

int main() {
  Solution s;
  
  return 0;
}
