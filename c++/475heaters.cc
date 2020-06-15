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
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int res = 0, i = 0, j = 0;
    const int m = houses.size(), n = heaters.size() - 1;
    for (int i = 0; i < m; ++i) {
      while (j < n && abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i])) ++j;
      res = max(res, abs(heaters[j] - houses[i]));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
