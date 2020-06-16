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
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    // sort(timeSeries.begin(), timeSeries.end());
    if (timeSeries.empty() || duration == 0) return 0;
    int res = 0, start = timeSeries.front(), last_to = start + duration;
    for (int i = 1, stop = timeSeries.size(); i < stop; ++i) {
      if (timeSeries[i] <= last_to) {
        last_to = timeSeries[i] + duration;
      } else {
        res += last_to - start;
        start = timeSeries[i];
        last_to = start + duration;
      }
    }
    res += last_to - start;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
