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
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    vector<vector<int>> m (n, vector<int> (n, INT_MIN));
    function<int(int, int)> score =
        [&] (int l, int r) {
          if (l == r) return piles[l];
          if (m[l][r] != INT_MIN) return m[l][r];
          return m[l][r] = max(piles[l] - score(l + 1, r),
                               piles[r] - score(l, r - 1));
        };
    return score(0, n - 1) > 0;
  }
};

class Solution1 {
 public:
  bool stoneGame(vector<int>& piles) {
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
