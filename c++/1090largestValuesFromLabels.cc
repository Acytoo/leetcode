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
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                            int num_wanted, int use_limit) {
    const int n = values.size();
    vector<pair<int, int>> vls;  // value ->label
    vls.reserve(n);
    for (int i = 0; i < n; ++i) vls.emplace_back(values[i], labels[i]);
    sort(vls.rbegin(), vls.rend());
    unordered_map<int, int> m;  // lavel -> use_count
    int res = 0, idx = 0;
    const int nn = vls.size();

    while (idx < nn && num_wanted > 0) {
      if (++m[vls[idx].second] > use_limit) {
        ++idx;
        continue;
      }
      res += vls[idx].first;
      --num_wanted;
      ++idx;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
