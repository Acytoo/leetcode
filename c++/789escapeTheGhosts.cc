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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    const int dis = abs(target[0]) + abs(target[1]);
    for (const auto gho: ghosts)
      if (abs(gho[0]-target[0]) + abs(gho[1]-target[1]) <= dis)
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
