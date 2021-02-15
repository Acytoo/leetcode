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
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    const int m = mat.size();
    vector<pair<int, int>> sums;
    sums.reserve(mat.size());
    for (int i = 0; i < m; ++i)
      sums.emplace_back(accumulate(mat[i].begin(), mat[i].end(), 0), i);
    sort(sums.begin(), sums.end());
    vector<int> res;
    for (int i = 0; i < k; ++i)
      res.emplace_back(sums[i].second);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
