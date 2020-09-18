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
  int diagonalSum(vector<vector<int>>& mat) {
    const int n = mat.size();
    int res = 0;
    for (int l = 0, r = n - 1; l < r; ++l, --r)
      res += mat[l][l] + mat[l][r] + mat[r][l] + mat[r][r];
    if (n & 1) res += mat[n>>1][n>>1];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
