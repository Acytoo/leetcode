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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    for (const auto &op: ops) {
      m = min(m, op[0]);
      n = min(n, op[1]);
    }
    return m * n;
  }
};

int main() {
  Solution s;
  
  return 0;
}
