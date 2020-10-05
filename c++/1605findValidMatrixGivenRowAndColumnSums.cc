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
class Solution {  // 100ms
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    const int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m, vector<int> (n));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        const int x = min(rowSum[i], colSum[j]);
        rowSum[i] -= x;
        colSum[j] -= x;
        res[i][j] = x;
      }
    return res;
  }
};

class Solution1 {  // 110+ms
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    const int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m, vector<int> (n));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        res[i][j] = min(rowSum[i], colSum[j]);
        rowSum[i] -= res[i][j];
        colSum[j] -= res[i][j];
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
