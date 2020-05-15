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
  int minFallingPathSum(vector<vector<int>>& A) {
    const int m = A.size() - 1, n = A.front().size() - 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 0; j <= n; ++j) {
        int sum = A[i - 1][j];
        if (j > 0) sum = min(sum, A[i - 1][j - 1]);
        if (j < n) sum = min(sum, A[i - 1][j + 1]);
        A[i][j] += sum;
      }
    return *min_element(A.back().begin(), A.back().end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
