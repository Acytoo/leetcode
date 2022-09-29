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
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length + 1, 0);
    for (const auto update : updates) {
      res[update[0]] += update[2];
      res[update[1] + 1] -= update[2];
    }
    for (int i = 1; i < length; ++i) res[i] += res[i - 1];
    res.pop_back();
    return res;
  }
};

class Solution_TLE {  // simulation, bruce force
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length);
    for (const auto update : updates)
      for (int i = update[0], stop = update[1], inc = update[2]; i <= stop; ++i)
        res[i] += inc;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
