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

// 1 <= logs.length <= 100
// 1950 <= birthi < deathi <= 2050

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    char years[2051];
    memset(years, 0, sizeof years);
    for (const auto & log : logs) {
      ++years[log[0]];
      --years[log[1]];
    }
    int cur = 0, max_population = 0, res = 0;
    for (int i = 1950; i <= 2050; ++i) {
      cur += years[i];
      if (cur > max_population) {
        max_population = cur;
        res = i;
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
