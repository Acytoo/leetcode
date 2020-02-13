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
class Solution {
 public:
  int maxStudents(vector<vector<char>>& seats) {
    int m = seats.size();
    int n = seats[0].size();

    vetor<vector<int>> dp(m+1, vector<int>(1<<n));
    for (int i=0; i<m; ++i)
      for (int l=0, stop_l=1<<n; l<stop_l; ++l)
        for (int c=0; c<stop_l;  ++c) {
          bool flag = true;
          for (int j=0; flag && j<n; ++j) {
            if (!(c & (1<<j)))
              continue;
            if (seats[i][j] == '#')
              flag = false;
            bool lt = j == 0? false: (c&(1<<(j-1)));
            bool rt = j == n-1? false: (c&(1<<(j+1)));
            bool ul = (j == 0 || i == 0)? false: (l&(1<<(j-1)));
            bool ur = (j == n-1 || i == 0)? false: (l&(1<<(j+1)));
            if (lt || rt || ul || ur)
              flag = false;
          }
          if (flag)
            dp[i+1][c] = max(dp[i+1][c], dp[i][l] + __builtin_popcount(c));
        }
    return *max_element(dp[m].begin(), dp[m].end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
