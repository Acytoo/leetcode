#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
void showMatrix(vector<vector<int>> &matrix) {
  cout << endl;
  for (auto row = matrix.begin(), endRow = matrix.end(); row != endRow; ++row) {
    for (auto col = (*row).begin(), endCol = (*row).end(); col != endCol; ++col)
      cout << *col << " ";
    cout << endl;
  }
}

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int i=0, j=0, m = matrix.size(), n = matrix[0].size();
    bool colFlag = false, rowFlag = false;

    for (i=0; i < m; ++i) {
      for (j=0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          if (i == 0)
            rowFlag = true;
          if (j == 0)
            colFlag = true;
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (i = 1; i < m; ++i)
      if (matrix[i][0] == 0)
        for (j = 1; j < n; ++j)
          matrix[i][j] = 0;

    for (j=1; j < n; ++j)
      if (matrix[0][j] == 0)
        for (i=1; i < m; ++i)
          matrix[i][j] = 0;

    if (rowFlag)
        for (j=0; j < n; ++j)
          matrix[0][j] = 0;
    if (colFlag)
        for (i=0; i < m; ++i)
          matrix[i][0] = 0;

  }
};


int main() {
  Solution s;
  vector<vector<int>> a = // {{1,1,1},{0,1,2}};

  //   {
  //                          {0,1,2,0},
  //                          {3,4,5,2},
  //                          {1,3,1,5}
  // };

  // {{1,1,1}, {1,0,1}, {1,1,1}};
    // {{1,0,3}};
    {{-4,-2147483648,6,-7,0},{-8,6,-8,-6,0},{2147483647,2,-9,-6,-10}};
  showMatrix(a);
  cout << "ori" << endl;
  s.setZeroes(a);
  showMatrix(a);
  return 0;
}
