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
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      bitset<10> nums;
      for (int j = 0; j < 9; ++j)
        if (board[i][j] > '0')
          if (nums[board[i][j] - '0'])
            return false;
          else
            nums[board[i][j]-'0'] = 1;
    }
    for (int j = 0; j < 9; ++j) {
      bitset<10> nums;
      for (int i = 0; i < 9; ++i)
        if (board[i][j] > '0')
          if (nums[board[i][j] - '0'])
            return false;
          else
            nums[board[i][j]-'0'] = 1;
    }
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j) {
        bitset<10> nums;
        for (int ii = i * 3, stopi = ii + 3; ii < stopi; ++ii)
          for (int jj = j * 3, stopj = jj + 3; jj < stopj; ++jj)
            if (board[ii][jj] > '0')
              if (nums[board[ii][jj] - '0'])
                return false;
              else
                nums[board[ii][jj]-'0'] = 1;
      }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
