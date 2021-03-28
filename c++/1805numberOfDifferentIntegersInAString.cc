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
  int numDifferentIntegers(string_view word) {
    unordered_set<string_view> s;
    for (int l = -1, r = 0, n = word.size(); r < n; ++r) {
      if (word[r] > '9') continue;
      l = r;
      while (r < n && word[r] <= '9') ++r;
      while (l < r && word[l] == '0') ++l;
      s.insert(word.substr(l, r - l));  // if l == r, we have 0 denoted as '' inserted
    }
    return s.size();
  }
};

int main() {
  Solution s;
  
  return 0;
}
