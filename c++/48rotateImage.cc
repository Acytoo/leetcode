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
    int n = m.size();
    // int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int t = 0, b = n - 1, l = 0, r = b;
    while (n > 1) {
      for (int i = 0, stop = n - 1; i < stop; ++i) {
        int tmp = m[t][l + i];
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
