#include <iostream>
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
#include <set>
#include <functional>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  int tilingRectangle(int n, int m) {
    if (n > m) return tilingRectangle(m, n);
    int res = n * m;;           // Maximum
    vector<int> h(n);
    function<void(int)> dfs = [&](int cur) {
                                if (cur >= res) return;
                                auto it = min_element(h.begin(), h.end());
                                if (*it == m) {
                                  res = cur;
                                  return;
                                }
                                int low = *it;
                                int s = it - h.begin();
                                int e = s;
                                while (e < n && h[e] == h[s] && (e-s+1+low) <= m) ++e;
                                for (int i=--e; i>=s; --i) {
                                  int size = i - s + 1;
                                  for (int j=s; j<=i; ++j) h[j] += size;
                                  dfs(cur+1);
                                  for (int j=s; j<=i; ++j) h[j] -= size;
                                }
                              };
    dfs(0);
    return res;
  }
};

int main() {
  Solution s;
  cout << s.tilingRectangle(3, 2) << endl;
  return 0;
}
