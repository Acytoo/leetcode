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
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    const int r = matrix.size(), c = matrix[0].size();
    m_ = vector<vector<int>> (r + 1, vector<int> (c + 1));
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        m_[i][j] = matrix[i - 1][j - 1] + m_[i - 1][j] + m_[i][j - 1] - m_[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return m_[row2 + 1][col2 + 1] - m_[row2 + 1][col1] - m_[row1][col2 + 1] + m_[row1][col1];
  }
 private:
  vector<vector<int>> m_;
};

class NumMatrix_OLD {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    m_.clear();
    int r = matrix.size();
    if (r == 0)
      return ;
    int c = matrix[0].size();
    m_ = vector<vector<int>> (r+1, vector<int> (c+1, 0));
    for (int i=1; i<=r; ++i)
      for (int j=1; j<=c; ++j)
        m_[i][j] = matrix[i-1][j-1] + m_[i-1][j] + m_[i][j-1] - m_[i-1][j-1];

  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (m_.empty())
      return 0;
    return m_[row2+1][col2+1] - m_[row2+1][col1] - m_[row1][col2+1] + m_[row1][col1];
  }
 private:
  vector<vector<int>> m_;
};


int main() {
  Solution s;
  
  return 0;
}
