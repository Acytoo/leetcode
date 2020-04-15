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
class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    vector<vector<int>> cards (10, vector<int> (10));
    for (const auto &d: dominoes)
      if (d[0] < d[1])
        ++cards[d[0]][d[1]];
      else
        ++cards[d[1]][d[0]];

    int res = 0;
    for (int i=1; i<10; ++i)
      for (int j=1; j<10; ++j)
        if (cards[i][j] >= 2)
          res += ((cards[i][j] - 1) * cards[i][j]) >> 1;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
