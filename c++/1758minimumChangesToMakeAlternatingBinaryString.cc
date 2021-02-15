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
  int minOperations(string s) {
    int res0 = 0, res1 = 0;  // res0: alternating string start with 0
    for (int i = 0, n = s.size(); i < n; ++i) {
      res0 += s[i] == ((i & 1) ? '1' : '0');
      res1 += s[i] == ((i & 1) ? '0' : '1');
    }
    return min(res0, res1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
