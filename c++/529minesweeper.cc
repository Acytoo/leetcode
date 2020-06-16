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
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    const int m = board.size(), n = board.front().size();
    function<void(int, int)> dfs =
        [&] (const int x, const int y) {
          int cnt = 0;
          for (int i = x - 1, stopi = x + 1; i <= stopi; ++i)
            for (int j = y - 1, stopj = y + 1; j <= stopj; ++j)
              if (i >= 0 && i < m && j >= 0 && j < n)
                cnt += board[i][j] == 'M';
          if (cnt) {
            board[x][y] = '0' + cnt;
            return ;
          }
          board[x][y] = 'B';
          for (int i = x - 1, stopi = x + 1; i <= stopi; ++i)
            for (int j = y - 1, stopj = y + 1; j <= stopj; ++j)
              if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'E')
                dfs(i, j);
        };
    if (board[click[0]][click[1]] == 'M')
      board[click[0]][click[1]] = 'X';
    else
      dfs(click[0], click[1]);
    return board;
  }
};

int main() {
  Solution s;
  
  return 0;
}
