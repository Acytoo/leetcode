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
// DP
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minFlipsMonoIncr(string S) {
    int dp0 = 0, dp1 = 0;
    for (int i = 0, stop = S.size(); i < stop; ++i) {
      int dp0_bk = dp0;
      dp0 += S[i] == '1';
      dp1 = min(dp0_bk, dp1) + (S[i] == '0');
    }
    return min(dp0, dp1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
