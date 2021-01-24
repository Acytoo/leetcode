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

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// 1 <= mat[i][j] <= 100

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // From huahua
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const int m = mat.size(), n = mat[0].size();
    vector<deque<int>> qs (m + n);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        qs[i - j + n].push_back(mat[i][j]);
    for (auto &q: qs)
      sort(q.begin(), q.end());
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        mat[i][j] = qs[i - j + n].front();
        qs[i - j + n].pop_front();
      }
    return mat;
  }
};

int main() {
  Solution s;
  
  return 0;
}
