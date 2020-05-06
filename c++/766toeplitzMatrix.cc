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

// matrix[i][j] == matrix[i + 1][j + 1]
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size() - 1, n = matrix.back().size() - 1;
    for (int i = 0; i < m; ++i) {
      const int ii = i + 1;
      for (int j = 0; j < n; )
        if (matrix[i][j] != matrix[ii][++j]) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
