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
  int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
    const int n = books.size();
    vector<int> dp (n, 12345678);  // 12345678: some large number
    dp[0] = books[0][1];
    for (int i = 0; i < n; ++i) {
      int w = 0, h = 0;
      for (int j = i; j < n; ++j) {
        if ((w += books[j][0]) > shelf_width) break;
        h = max(h, books[j][1]);
        dp[j] = min(dp[j], (i == 0? 0: dp[i - 1]) + h);
      }
    }
    return dp.back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
