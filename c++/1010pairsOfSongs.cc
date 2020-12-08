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
  int numPairsDivisibleBy60(vector<int>& time) {
    int rems[60], res = 0;
    memset(rems, 0, sizeof(rems));
    for (const int t: time) {
      res += rems[(600 - t) % 60];
      ++rems[t % 60];
    }
    return res;
  }
};

class Solution_WRONG {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int rems[61], res = 0;
    memset(rems, 0, sizeof(rems));
    for (const int t: time) {
      const int rem = t % 60; // [60, 60, 60]
      res += rems[60 - rem];
      ++rems[rem];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
