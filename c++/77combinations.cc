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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    // int sz = n;
    // for (int i = n - 1, stop = n - k + 1; i >= stop; --i) sz *= i;
    // for (int i = k; i >= 2; --i) sz /= i;
    // res.reserve(sz);
    vector<int> cur;
    function<void(int)> dfs =
        [&] (int idx) {
          if (cur.size() == k) {
            res.push_back(cur);
            return ;
          }
          for (int i = idx; i < n; ++i) {
            cur.emplace_back(i + 1);
            dfs(i + 1);
            cur.pop_back();
          }
        };
    dfs(0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
