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
class Solution { // slower
 public:
  bool exist(vector<vector<char>>& board, string word) {
    const int m = board.size(), n = board[0].size();
    const int stop = word.size();
    constexpr int dirs[] = {0, -1, 0, 1, 0};
    function<bool(int, int, int)> dfs = [&] (const int x, const int y, const int idx) {
      if (x < 0 || x >= m || y < 0 || y >= n) return false;
      if (board[x][y] == word[idx] && idx + 1 == stop) return true;
      if (board[x][y] != word[idx]) return false;
      const char ori = board[x][y];
      board[x][y] = '-';
      for (int i = 0; i < 4; )
        if (dfs(x + dirs[i], y + dirs[++i], idx + 1))
          return true;
      board[x][y] = ori;
      return false;
    };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (dfs(i, j, 0)) return true;
    return false;
  }
};

// DFS
class Solution_OLD {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    const int m = board.size(), n = board[0].size();
    const int stop = word.size();
    constexpr int dirs[] = {0, -1, 0, 1, 0};
    function<bool(int, int, int)> dfs = [&] (const int x, const int y, const int idx) {
      if (idx >= stop) return true;
      for (int i = 0; i < 4; ) {
        const int nx = x + dirs[i];
        const int ny = y + dirs[++i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;
        if (board[nx][ny] == word[idx]) {
          const char ori = board[nx][ny];
          board[nx][ny] = '-';
          if (dfs(nx, ny, idx + 1)) return true;
          board[nx][ny] = ori;
        }
      }
      return false;
    };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (board[i][j] == word[0]) {
          const char tmp = board[i][j];
          board[i][j] = '-';
          if (dfs(i, j, 1)) return true;
          board[i][j] = tmp;
        }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
