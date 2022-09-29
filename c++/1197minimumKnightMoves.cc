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
class Solution_TLE {
 public:
  int minKnightMoves(int tx, int ty) {
    constexpr int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
    constexpr int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<vector<bool>> seen (610, vector<bool>(610, false));
    deque<pair<int, int>> dq;
    dq.emplace_back(0, 0);
    seen[0][0] = true;
    int res = 0;
    while (!dq.empty()) {
      int n = dq.size();
      while (--n >= 0) {
        int x = dq.front().first, y = dq.front().second; dq.pop_front();
        if (x == tx && y == ty) return res;
        for (int i = 0; i < 8; ++i) {
          const int nx = x + dx[i], ny = y + dy[i];
          if (seen[nx + 303][ny + 303]) continue;
          seen[x + 303][y + 303] = true;
          dq.emplace_back(nx, ny);
        }
      }
      ++res;
    }
    return -1;
  }
};

// The key board is symetric, and range is [-300, 300]
// and each step is central symetric

class Solution_TLE {
 public:
  int minKnightMoves(int x, int y) {
    int res = 0;
    deque<pair<int, int>> dq;
    dq.emplace_back(0, 0);
    unordered_set<string> s;
    function<void(int, int)> seen = [&] (int x, int y) {
      string cur = to_string(x) + '_' + to_string(y);
      if (s.count(cur) == 0) dq.emplace_back(x, y);
    };
    seen(0, 0);
    while (!dq.empty()) {
      int n = dq.size();
      ++res;
      while (--n >= 0) {
        int i = dq.front().first, j = dq.front().second; dq.pop_front();

        int ni = i + 1, nj = j + 2;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i + 1, nj = j - 2;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i - 1, nj = j + 2;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i - 1, nj = j - 2;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i + 2, nj = j + 1;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i + 2, nj = j - 1;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i - 2, nj = j + 1;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

        ni = i - 2, nj = j - 1;
        if (ni == x && nj == y) return res;
        seen(ni, nj);

      }
    }
    return 0;
  }
};

int main() {
  Solution s;
  cout << s.minKnightMoves(5, 3) << endl;
  return 0;
}
