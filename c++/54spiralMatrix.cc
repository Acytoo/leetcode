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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    if (m == 0) return {};
    const int n = matrix[0].size();
    if (n == 0) return {};

    int left = m * n, u = 0, d = m - 1, l = 0, r = n - 1, x = 0, y = -1, dir = 0;
    vector<int> res;
    res.reserve(left);
    while (--left >= 0) {
      switch (dir) {
        case 0:
          if (y < r) {
            ++y;
          } else {
            dir = 1;
            ++u;
            ++x;
          }
          break;
        case 1:
          if (x < d) {
            ++x;
          } else {
            dir = 2;
            --r;
            --y;
          }
          break;
        case 2:
          if (y > l) {
            --y;
          } else {
            dir = 3;
            --d;
            --x;
          }
          break;
        case 3:
          if (x > u) {
            --x;
          } else {
            dir = 0;
            ++l;
            ++y;
          }
      }
      res.emplace_back(matrix[x][y]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
