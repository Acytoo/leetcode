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

// colsum == 0: both row-0 and row-1 is 0, colsum == 2, both = 1
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    const int n = colsum.size();
    vector<vector<int>> res (2, vector<int> (n));
    for (int i = 0; i < n; ++i)
      if (colsum[i] == 2) {
        res[0][i] = res[1][i] = 1;
        --upper; --lower;
      }

    for (int i = 0; i < n; ++i)
      if (colsum[i] == 1)
        if (upper < lower) {
          res[1][i] = 1;
          --lower;
        } else {  // >=
          res[0][i] = 1;
          --upper;
        }
    if (upper != 0 || lower != 0) return {};

    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
