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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows, vector<int>());
    res[0].push_back(1);
    for (int row = 1; row < numRows; ++row) {
      res[row].resize(row + 1);
      res[row].front() = res[row].back() = 1;
      for (int col = 1; col < row; ++col)
        res[row][col] = res[row - 1][col - 1] + res[row - 1][col];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
