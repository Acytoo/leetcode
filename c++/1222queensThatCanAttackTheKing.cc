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
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>> res;
    vector<vector<int>> board(8, vector<int>(8));
    for (auto q : queens) board[q[0]][q[1]] = 1;
    const int x = king[0], y = king[1];
    for (int i = x - 1; i >= 0; --i)
      if (board[i][y] == 1) {
        res.emplace_back(initializer_list<int>{i, y});
        break;
      }
    for (int i = x + 1; i < 8; ++i)
      if (board[i][y] == 1) {
        res.emplace_back(initializer_list<int>{i, y});
        break;
      }
    for (int j = y - 1; j >= 0; --j)
      if (board[x][j] == 1) {
        res.emplace_back(initializer_list<int>{x, j});
        break;
      }
    for (int j = y + 1; j < 8; ++j)
      if (board[x][j] == 1) {
        res.emplace_back(initializer_list<int>{x, j});
        break;
      }
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
      if (board[i][j] == 1) {
        res.emplace_back(initializer_list<int>{i, j});
        break;
      }
    for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j)
      if (board[i][j] == 1) {
        res.emplace_back(initializer_list<int>{i, j});
        break;
      }
    for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j)
      if (board[i][j] == 1) {
        res.emplace_back(initializer_list<int>{i, j});
        break;
      }
    for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j)
      if (board[i][j] == 1) {
        res.emplace_back(initializer_list<int>{i, j});
        break;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
