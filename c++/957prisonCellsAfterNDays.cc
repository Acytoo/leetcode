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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// new cells[i] = ~(cells[i-1] ^ cells[i+1]) or cells[i-1] ^ cells[i+1] ^ 1
class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    if (N == 0) return cells;
    N %= 14;
    vector<int> res (8);
    if (N == 0) N += 14;
    while (--N >= 0) {
      for (int i=1; i<7; ++i)
        res[i] = cells[i-1] ^ cells[i+1] ^ 1;
      cells = res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
