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
  vector<long long> minimumCosts(vector<int>& regular, vector<int>& express,
                                 int expressCost) {
    const int n = regular.size();
    vector<long long> res(n);
    // min cost to reach current stop in regular route
    long long dpReg = 0;
    // min cost to reach current stop in express route
    long long dpExp = expressCost;

    for (int i = 0; i < n; ++i) {
      const long long prevReg = dpReg;
      const long long prevExp = dpExp;
      dpReg = min(prevReg + regular[i], prevExp + 0 + regular[i]);
      dpExp = min(prevReg + expressCost + express[i], prevExp + express[i]);
      res[i] = min(dpReg, dpExp);
    }

    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
