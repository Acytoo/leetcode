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
// 1 <= function_id <= 9
// 1 <= z <= 100
// 1 <= x, y <= 1000
class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> res;
    for (int x=1; x<=1000; ++x)
      for (int y=1; y<=1000; ++y) {
        int tmp = customfunction.f(x, y);
        if (tmp == z)
          res.emplace_back(initializer_list<int>{x, y});
        else if (tmp > z)
          break;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
