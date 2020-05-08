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
  bool validTicTacToe(vector<string>& board) {
    int x = 0, o = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (board[i][j] == 'X')
          ++x;
        else if (board[i][j] == 'O')
          ++o;
    if (x != o && x != o + 1) return false;
    auto win = [&] (const char c) -> int {  // how many times one player wins
                 int row = (board[0][0] == c && board[0][1] == c && board[0][2] == c) +
                           (board[1][0] == c && board[1][1] == c && board[1][2] == c) +
                           (board[2][0] == c && board[2][1] == c && board[2][2] == c);
                 int col = (board[0][0] == c && board[1][0] == c && board[2][0] == c) +
                           (board[0][1] == c && board[1][1] == c && board[2][1] == c) +
                           (board[0][2] == c && board[1][2] == c && board[2][2] == c);
                 int dia = (board[0][0] == c && board[1][1] == c && board[2][2] == c) +
                           (board[0][2] == c && board[1][1] == c && board[2][0] == c);
                 return row + col + dia;
               };
    int xx = win('X'), oo = win('O');
    if (xx > 0 && oo > 0) return false;
    if (oo > 0)
      if (oo == 1)
        return x == o;
      else
        return false;
    if (xx > 0) return x == o + 1;
    return true;
  }
};

int main() {
  Solution s;
  vector<string> a = {"XXX","OOX","OOX"};
  a = {"XOX","OOX","XO "};
  cout << s.validTicTacToe(a) << endl;
  return 0;
}

/*
Only X can win "twice", whichs take 5 positions
true:
X X X
X O O
X O O

true:
X X X
O X O
O O X

true:
X O O
X X O
X O X

false:
O O O
O X X
O X X

*/
