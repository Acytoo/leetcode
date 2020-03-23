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
class Solution_TLE {
 public:
  int strStr(string s, string t) {
    int n = t.size();
    if (n == 0)
      return 0;
    for (int i=0, stop=s.size(); i<stop; ++i)
      if (s[i] == t[0]) {
        int j = -1;
        while (++j<n)
          if (s[i+j] != t[j])
            break;
        if (j >= n)
          return i;
      }
    return -1;
  }
};

class Solution {
 public:
  int strStr(string s, string t) {
    int n = t.size();
    if (n == 0)
      return 0;
    for (int i=0, stop=s.size(); i<stop; ++i)
      if (s[i] == t[0])
        if (s.substr(i, n) == t)
          return i;
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
