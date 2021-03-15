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
  int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, int> m;
    for (const auto &e : edges) {
      ++m[e[0]];
      ++m[e[1]];
    }
    int res = -1, occ = 0;
    for (const auto &[k, v] : m)
      if (v > occ) {
        occ = v;
        res = k;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
