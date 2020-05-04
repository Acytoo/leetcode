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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    const int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> m (l1 + 1, vector<int> (l2 + 1, INT_MAX));
    function<int(int, int)> dp =
        [&] (int i, int j) {
          if (i == 0 && j == 0) return 0;
          if (m[i][j] != INT_MAX) return m[i][j];
          if (i == 0) return m[i][j] = dp(i, j - 1) + s2[j - 1];
          if (j == 0) return m[i][j] = dp(i - 1, j) + s1[i - 1];
          if (s1[i - 1] == s2[j - 1]) return m[i][j] = dp(i - 1, j - 1);
          return m[i][j] = min(dp(i - 1, j) + s1[i - 1], dp(i, j - 1) + s2[j - 1]);
        };
    return dp(l1, l2);
  }
};

int main() {
  Solution s;
  cout << s.minimumDeleteSum("delete", "leet") << endl;
  return 0;
}
