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
  int findLUSlength(vector<string>& strs) {
    unordered_map<string, int> m;
    for (auto &s : strs) {
      for (int i = 0, n = s.size(), stop = 1 << n; i < stop; ++i) {
        string t;
        for (int j = 0; j < n; ++j) {
          if ((i >> j) & 1) t += s[j];
        }
        ++m[t];
      }
    }
    int res = -1;
    for (auto &a : m)
      if (a.second == 1)
        res = max(res, (int)a.first.size());
    return res;
  }
};

class Test {  // Only for combinations
 public:
  void findAllSubStrs(string s) {
    for (int i = 0, n = s.size(), stop = (1 << n); i < stop; ++i) {
      string t = "";
      for (int j = 0; j < n; ++j)
        if ((i >> j) & 1)
          t += s[j];
      cout << t << endl;
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
