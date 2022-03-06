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
  void rotate(vector<vector<int>>& m) {
    for (int i = 0, n = m.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        swap(m[i][j], m[j][i]);
    for (auto &row : m) reverse(row.begin(), row.end());
  }
};

class Solution1 {  // brute force
 public:
  void rotate(vector<vector<int>>& m) {
    int n = m.size();
    int t = 0, b = n - 1, l = 0, r = n - 1;
    while (n > 1) {
      for (int i = 0, stop = n - 1; i < stop; ++i) {
        const int tmp = m[t][l + i];
        m[t][l + i] = m[b - i][l];
        m[b - i][l] = m[b][r - i];
        m[b][r - i] = m[t + i][r];
        m[t + i][r] = tmp;
      }
      ++t;
      --b;
      ++l;
      --r;
      n -= 2;
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
