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
  int minimumDeviation(vector<int>& nums) {
    set<int> s;
    for (const int x: nums)
      s.insert(x & 1 ? x << 1 : x);
    int res = *rbegin(s) - *begin(s);
    while ((*rbegin(s) & 1) == 0) {
      s.insert(*rbegin(s) >> 1);
      s.erase(*rbegin(s));
      res = min(res, *rbegin(s) - *begin(s));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
