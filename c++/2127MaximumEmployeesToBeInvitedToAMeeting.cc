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

// n == favorite.length
// 2 <= n <= 10^5
// 0 <= favorite[i] <= n - 1
// favorite[i] != i


static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // Topological sort
 public:
  int maximumInvitations(vector<int>& favorite) {
    const int n = favorite.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) g[i].push_back(favorite[i]);
    vector<int> tmp;
    vector<int> colors(n);  // 0: white, 1: gray, 2: black
    function<int> dfs = [&] (const int idx) {
      colors[idx] = black;
      for (
    };
  }
};

int main() {
  Solution s;
  
  return 0;
}
