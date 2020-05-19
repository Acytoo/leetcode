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
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    const int m = A.size(), n = B.size();
    vector<vector<int>> res;
    res.reserve(min(m, n));
    int i = 0, j = 0;
    while (i < m && j < n) {
      const int s = max(A[i][0], B[j][0]),
                e = min(A[i][1], B[j][1]);
      if (s <= e) res.emplace_back(initializer_list<int>{s, e});
      if (A[i][1] < B[j][1])
        ++i;
      else
        ++j;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
