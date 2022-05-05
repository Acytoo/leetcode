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
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    vector<vector<int>> g(s.size());
    for (const auto &p : pairs) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    unordered_set<int> seen;
    vector<int> idx;
    string cur;
    function<void(int)> dfs = [&] (const int i) {
      if (seen.count(i)) return;
      seen.insert(i);
      idx.push_back(i);
      cur += s[i];
      for (const int nxt : g[i]) dfs(nxt);
    };
    string res = s;
    for (int i = 0, n = s.size(); i < n; ++i) {
      if (seen.count(i)) continue;
      idx.clear();
      cur.clear();
      dfs(i);
      sort(cur.begin(), cur.end());
      sort(idx.begin(), idx.end());
      for (int j = 0, stop = idx.size(); j < stop; ++j)
        res[idx[j]] = cur[j];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
