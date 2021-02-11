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
  bool isAnagram(string s, string t) {
    const int m = s.size(), n = t.size();
    if (m != n) return false;
    vector<int> ss('z' + 1), tt('z' + 1);
    for (const char c: s) ++ss[c];
    for (const char c: t) ++tt[c];
    for (int c = 'a'; c <= 'z'; ++c)
      if (ss[c] != tt[c]) return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
