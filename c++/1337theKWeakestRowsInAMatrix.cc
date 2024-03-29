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
    const int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> weak_idx;
    for (int i = 0; i < m; ++i)
      weak_idx.emplace_back(accumulate(mat[i].begin(), mat[i].end(), 0), i);
    sort(weak_idx.begin(), weak_idx.end(), [&] (const auto &a, const auto&b) {
      if (a.first != b.first) return a.first < b.first;
      return a.second < b.second;
    });
    vector<int> res(k);
    while (--k >= 0) res[k] = weak_idx[k].second;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
