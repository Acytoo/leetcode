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
// From huahua
class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    const int n = satisfaction.size();
    sort(satisfaction.rbegin(), satisfaction.rend());  // reverse sort
    int res = 0, prefix = 0;
    for (const int satis: satisfaction) {
      if ((prefix += satis) <= 0) break;
      res += prefix;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
