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
