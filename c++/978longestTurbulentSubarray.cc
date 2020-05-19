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
  int maxTurbulenceSize(vector<int>& A) {
    int dp1 = 1, dp2 = 1, res = 1;
    for (int i = 1, stop = A.size(); i < stop; ++i) {
      if (A[i] < A[i - 1]) {
        dp1 = dp2 + 1;
        dp2 = 1;
      } else if (A[i] > A[i - 1]) {
        dp2 = dp1 + 1;
        dp1 = 1;
      } else {
        dp1 = dp2 = 1;
      }
      res = max({res, dp1, dp2});
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
