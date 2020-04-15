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
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> los (1001);
    for (const auto &t: trips) {
      los[t[1]] -= t[0];
      los[t[2]] += t[0];
    }
    for (const auto lo: los)
      if ((capacity += lo) < 0)
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
