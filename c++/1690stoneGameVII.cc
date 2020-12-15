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
// From huahua
class Solution{
 public:
  int stoneGameVII(vector<int> &stones) {
    const int n = stones.size();
    vector<vector<int>> cache (n, vector<int> (n, INT_MAX));
    function<int(int, int, int)> helper = [&] (int l, int r, int sum) -> int {
      if (l >= r) return 0;
      if (cache[l][r] == INT_MAX) {
        cache[l][r] = max(sum - stones[l] - helper(l + 1, r, sum - stones[l]),
                          sum - stones[r] - helper(l, r - 1, sum - stones[r]));
      }
      return cache[l][r];
    };
    return helper(0, n - 1, accumulate(stones.begin(), stones.end(), 0));
  }
};

int main() {
  Solution s;
  
  return 0;
}
