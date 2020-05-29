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
  string tictactoe(vector<vector<int>>& moves) {
    const int n = moves.size();
    if (n <= 4) return "Pending";

    vector<vector<char>> board (3, vector<char> (3, ' '));
    bool a = true;
    for (const auto &m: moves) {
      board[m[0]][m[1]] = a? 'A': 'B';
      a = !a;
    }
    // row or col
    for (int i = 0; i < 3; ++i) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
        return string(1, board[i][2]);
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        return string(1, board[2][i]);
    }
    // dia
    if (board[1][1] == ' ') return "Pending";
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return string(1, board[1][1]);
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return string(1, board[1][1]);
    return n == 9? "Draw": "Pending";
  }
};

class Solution1 {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    const int n = moves.size();
    if (n <= 4) return "Pending";

    vector<vector<char>> board (3, vector<char> (3, ' '));
    bool a = true;
    for (const auto &m: moves) {
      board[m[0]][m[1]] = a? 'X': 'O';
      a = !a;
    }
    // row or col
    for (int i = 0; i < 3; ++i) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
        return board[i][2] == 'X'? "A": "B";
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        return board[2][i] == 'X'? "A": "B";
    }
    // dia
    if (board[1][1] == ' ') return "Pending";
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[1][1] == 'X'? "A": "B";
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[1][1] == 'X'? "A": "B";
    return n == 9? "Draw": "Pending";
  }
};

class Solution_WRONG {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    const int n = moves.size();
    if (n <= 4) return "Pending";
    const int k = n - 1, j = k - 2, i = j - 2;
    bool win = moves[i][0] == moves[j][0] && moves[j][0] == moves[k][0] || // same row
               moves[i][1] == moves[j][1] && moves[j][1] == moves[k][1] || // same col
               (moves[i][0] + moves[i][1] == 2 &&
                moves[j][0] + moves[j][1] == 2 &&
                moves[k][0] + moves[k][1] == 2) ||  // dia0
               (moves[i][0] == moves[i][1] &&
                moves[j][0] == moves[j][1] &&
                moves[k][0] == moves[k][1]); // dia1
    if (!win && n == 9) return "Draw";
    if (!win && n < 9) return "Pending";
    if (n == 6 || n == 8) return "B";
    return "A";  // 5, 7, 9
  }
};

int main() {
  Solution s;
  
  return 0;
}
