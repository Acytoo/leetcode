#include <iostream>
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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    if (m == 0) return {};
    const int n = matrix[0].size();
    if (n == 0) return {};

    const int mn = m * n;
    vector<int> res (mn);
    vector<vector<int>> dirs {{-1, 1}, {1, -1}};
    int r = 0, c = 0, k = 0;

    for (int i=0; i<mn; ++i) {
      res[i] = matrix[r][c];
      r += dirs[k][0];
      c += dirs[k][1];
      if (r == m) {--r; c += 2; k ^= 1;}
      if (c == n) {r += 2; --c; k ^= 1;}
      if (r == -1) {r = 0; k ^= 1;}
      if (c == -1) {c = 0; k ^= 1;}
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
