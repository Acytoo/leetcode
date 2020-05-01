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
  int findCircleNum(vector<vector<int>>& M) {
    const int n = M.size();
    function<void(int)> dfs =
        [&] (int cur) {
          for (int i=0; i<n; ++i) {
            if (M[cur][i] == 0) continue;
            M[cur][i] = M[i][cur] = 0;
            dfs(i);
          }
        };
    int res = 0;
    for (int i=0; i<n; ++i)
      if (M[i][i]) {
        ++res;
        dfs(i);
      }
    return res;
  }
};

class Solution1 {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    const int n = M.size();
    function<void(int)> dfs =
        [&] (int cur) {
          for (int i=0; i<n; ++i) {
            if (M[cur][i] == 0) continue;
            M[cur][i] = M[i][cur] = 0;
            dfs(i);
          }
        };
    int res = 0;
    for (int i=0; i<n; ++i)
      for (int j=i; j<n; ++j)
        if (M[i][j] == 1) {
          M[i][j] = M[j][i] = 0;
          ++res;
          dfs(j);
        }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
