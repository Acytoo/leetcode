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
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    map<int, int> start_idx;
    for (int i = 0; i < n; ++i) start_idx.emplace(intervals[i][0], i);
    vector<int> res;
    res.reserve(n);
    for (const auto &in: intervals) {
      auto it = start_idx.lower_bound(in[1]);
      if (it == start_idx.end())
        res.emplace_back(-1);
      else
        res.emplace_back(it->second);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
