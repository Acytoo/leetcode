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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    const int m = board.size(), n = board[0].size();
    int res = 0;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (board[i][j] == 'X' &&
            (i==0 || board[i-1][j]=='.') &&
            (j==0 || board[i][j-1]=='.'))
          ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
