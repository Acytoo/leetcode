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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> res;
    for (int i=0; i<R; ++i)
      for (int j=0; j<C; ++j)
        res.emplace_back(initializer_list<int>{i, j});
    sort(res.begin(), res.end(),
         [=] (const vector<int> &a, const vector<int> &b) {
           return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
         });
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
