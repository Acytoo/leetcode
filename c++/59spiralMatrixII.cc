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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res (n, vector<int> (n));
    int num = 0, left = n * n, x = 0, y = -1;
    int u = 0, d = n - 1, l = 0, r = n - 1, dir = 0;
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
      res[x][y] = ++num;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
