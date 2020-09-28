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
  vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> sectors (n + 1);
    for (int i = 0, stop = rounds.size() - 1; i < stop; ) {
      const int l = rounds[i], r = rounds[++i];
      if (l < r) {
        for (int i = l; i < r; ++i) ++sectors[i];
      } else {
        for (int i = l; i <= n; ++i) ++sectors[i];
        for (int i = 1; i < r; ++i) ++sectors[i];
      }
    }
    ++sectors[rounds.back()];
    vector<int> res;
    int most = 0;
    for (int i = 1; i <= n; ++i) {
      if (sectors[i] > most) {
        most = sectors[i];
        res.clear();
        res.emplace_back(i);
      } else if (sectors[i] == most) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
