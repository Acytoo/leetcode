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
  int minimumMoves(string s) {
    const int n = s.size();
    int res = 0;
    function<void(int)> helper = [&] (int idx) {
      while (idx < n && s[idx] == 'O') ++idx;
      if (idx >= n) return;
      ++res;
      helper(idx + 3);
    };
    helper(0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
