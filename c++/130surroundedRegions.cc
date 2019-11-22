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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    const int m = board.size();
    if (!m) return;
    const int n = board[0].size();

    function<void(int, int)> dfs = [&](int x, int y) {
                 if (x<0 || x>=n || y<0 || y>=m || board[y][x] != 'O')
                   return;
                 board[y][x] = 'G';
                 dfs(x-1, y);
                 dfs(x+1, y);
                 dfs(x, y-1);
                 dfs(x, y+1);
               };
    for (int y=0; y<m; ++y) {
      dfs(0, y);
      dfs(n-1, y);
    }

    for (int x=0; x<n; ++x) {
      dfs(x, 0);
      dfs(x, m-1);
    }

    map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};
    for (int y=0; y<m; ++y)
      for (int x=0; x<n; ++x)
        board[y][x] = v[board[y][x]];
  }
};

int main() {
  Solution s;
  
  return 0;
}
