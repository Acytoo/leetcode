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
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int res = 0, m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 1; j < n; ++j)
        matrix[i][j] += matrix[i][j - 1];

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        unordered_map<int, int> cntMap{{0, 1}};
        int cur = 0;
        for (int k = 0; k < m; ++k) {
          cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
          res += cntMap[cur - target];
          ++cntMap[cur];
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
