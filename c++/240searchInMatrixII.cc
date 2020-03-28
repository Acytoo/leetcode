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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int m = matrix.size();
    if (m == 0)
      return false;
    const int n = matrix[0].size();
    if (n == 0)
      return false;

    int r = 0, c = n-1;
    while (r < m && 0 <= c) {
      if (matrix[r][c] == target)
        return true;
      else if (matrix[r][c] < target)
        ++r;
      else
        --c;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
