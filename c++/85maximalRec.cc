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
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int r = matrix.size();
    if (r == 0)
      return 0;
    int c = matrix[0].size();
    vector<vector<int>> dp (r, vector<int> (c, 0));

    for (int i=0; i<r; ++i)
      for (int j=0; j<c; ++j)
        dp[i][j] = (matrix[i][j]=='0')? 0: (j==0? 1: dp[i][j-1]+1);

    // for (int i=0; i<r; ++i) {
    //   for (int j=0; j<c; ++j)
    //     cout << dp[i][j] << " ";
    //   cout << endl;
    // }

    int res = 0;
    for (int i=0; i<r; ++i)
      for (int j=0; j<c; ++j) {
        int len = INT_MAX;
        for (int k=i; k<r; ++k) {
          // cout << len << endl;
          len = min(len, dp[k][j]);
          if (len == 0)
            break;
          res = max(res, (k-i+1)*len);
        }
      }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
