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
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    constexpr int kSeed = 300;  // max matrix size
    auto boost_hash = [&] (vector<int> &row) {
                        unsigned int seed = kSeed;
                        for(auto &i: row) seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
                        return seed;
                      };
    auto rboost_hash = [&] (vector<int> &row) {
                         unsigned int seed = kSeed;
                         for(auto &i: row) seed ^= (i^1) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
                         return seed;
                      };
    unordered_map<unsigned int, int> m;
    for (auto &row: matrix)
      if (row.front() == 1)
        ++m[boost_hash(row)];
      else
        ++m[rboost_hash(row)];
    int res = 0;
    for (auto &[_, num]: m) res = max(res, num);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
