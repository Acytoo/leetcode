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
  int prefixCount(vector<string>& words, string pref) {
    int res = 0;
    for (const auto &w : words)
      if (w.find(pref) == 0)
        ++res;
    return res;
  }
};

class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    const int n = pref.size();
    int res = 0;
    for (const auto &w : words)
      if (pref == w.substr(0, n))
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
