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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  // Brute force
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    int res = 0;
    vector<vector<int>> matrix (n, vector<int> (m));
    for (const auto idx: indices) {
      for (int i=0; i<m; ++i) ++matrix[idx[0]][i];
      for (int j=0; j<n; ++j) ++matrix[j][idx[1]];
    }
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
        res += (matrix[i][j] & 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
