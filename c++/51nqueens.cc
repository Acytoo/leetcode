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
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> pos (n, -1);  // position of queen in each row
    function<bool(int, int)> valid =
        [&] (const int row, const int col) {
          for (int i = 0; i < row; ++i)
            if (col == pos[i] || abs(row - i) == abs(col - pos[i]))
              return false;
          return true;
        };
    function<void(int)> helper =
        [&] (const int cur_row) {
          if (cur_row == n) {
            vector<string> board (n, string(n, '.'));
            for (int i = 0; i < n; ++i)
              board[i][pos[i]] = 'Q';
            res.emplace_back(move(board));
            return ;
          }
          for (int i = 0; i < n; ++i)
            if (valid(cur_row, i)) {
              pos[cur_row] = i;
              helper(cur_row + 1);
              pos[cur_row] = -1;
            }
        };
    helper(0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
