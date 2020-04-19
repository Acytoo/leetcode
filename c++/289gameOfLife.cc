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
  void gameOfLife(vector<vector<int>>& board) {
    const int m = board.size();
    if (m == 0) return ;
    const int n = board[0].size();

    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        int nei = 0;
        for (int ii=max(0, i-1), stopi=min(m, i+2); ii<stopi; ++ii)
          for (int jj=max(0, j-1), stopj=min(n, j+2); jj<stopj;  ++jj)
            nei += board[ii][jj] & 1;
        if (nei == 3 || nei-board[i][j] == 3) board[i][j] |= 0b10;
      }
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        board[i][j] >>= 1;
  }
};


int main() {
  Solution s;
  
  return 0;
}
