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
  bool isSubsequence(string s, string t) {
    const int m = s.size(), n = t.size();
    if (m > n) return false;
    int i = 0, j = 0;
    while (i < m && j < n) {
      if (s[i] == t[j]) {
        ++i;
        ++j;
        continue;
      }
      ++j;
    }
    return i == m;
  }
};

int main() {
  Solution s;
  
  return 0;
}
