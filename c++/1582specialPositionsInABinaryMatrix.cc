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
// mat[i][j] is 0 or 1
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    const int m = mat.size(), n = mat[0].size();
    int res = 0;
    vector <int> row(m), col(n);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        row[i] += mat[i][j];
        col[j] += mat[i][j];
      }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        res += mat[i][j] && (row[i] == 1) && (col[j] == 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
