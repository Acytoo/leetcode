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

class Solution_TLE {
  // BFS
 public:
  int racecar(int target) {
    deque<pair<int, int>> dq;
    dq.emplace_back(0, 1);
    int res = 0;
    while (true) {
      int sz = dq.size();
      while (sz > 0) {
        auto tmp = dq.front(); dq.pop_front();
        const int position = tmp.first, speed = tmp.second;
        if (position == target) return res;
        dq.emplace_back(position + speed, speed * 2);
        dq.emplace_back(position, speed > 0 ? -1 : 1);
        --sz;
      }
      ++res;
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
