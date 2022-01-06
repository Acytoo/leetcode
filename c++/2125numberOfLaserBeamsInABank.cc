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

// m == bank.length
// n == bank[i].length
// 1 <= m, n <= 500
// bank[i][j] is either '0' or '1'

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // Brute force
 public:
  int numberOfBeams(vector<string>& bank) {
    int res = 0;
    const int m = bank.size(), n = bank[0].size();
    for (int i = 0; i < m; ++i) {
      int devices = 0;
      for (int c = 0; c < n; ++c)
        devices += (bank[i][c] == '1');
      if (devices == 0) continue;
      int next_row_devices = 0;
      int j = i + 1;
      while (j < m && next_row_devices == 0) {
        for (int c = 0; c < n; ++c)
          next_row_devices += (bank[j][c] == '1');
        ++j;
      }
      res += devices * next_row_devices;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
