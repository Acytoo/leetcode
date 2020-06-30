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
#include <bitset>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Trie tree
// coming soon ...
// DFS
class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    row_ = board.size();
    if (row_ == 0)
      return {};
    col_ = board[0].size();
    vector<string> res;
    for (const string& word: words)
      if (exist(board, word))
        res.emplace_back(std::move(word));
    return res;
  }
 private:
  int row_;
  int col_;

  bool exist(vector<vector<char>>& board, const string& word) {
    for (int i=0; i<row_; ++i)
      for (int j=0; j<col_; ++j)
        if (found(board, word, 0, i, j))
          return true;
    return false;
  }

  bool found(vector<vector<char>>& board, const string& word, int idx, int x, int y) {
    if (x<0 || x==row_ || y<0 || y==col_ || word[idx]!=board[x][y])
      return false;
    if (idx == word.length()-1)
      return true;
    char cur = board[x][y];  // use a mask '#'
    board[x][y] = '#';
    bool res = found(board, word, idx+1, x+1, y) ||
          found(board, word, idx+1, x-1, y) ||
          found(board, word, idx+1, x, y+1) ||
          found(board, word, idx+1, x, y-1);
    board[x][y] = cur;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
