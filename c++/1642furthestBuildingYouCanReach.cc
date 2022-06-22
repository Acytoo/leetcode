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

//1 <= heights.length <= 10^5
//1 <= heights[i] <= 10^6
//0 <= bricks <= 10^9
//0 <= ladders <= heights.length

static int x = []() { ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0, n = heights.size() - 1; i < n; ++i) {
      const int diff = heights[i + 1] - heights[i];
      if (diff <= 0) continue;
      pq.push(diff);
      if (pq.size() <= ladders) continue;
      if ((bricks -= pq.top()) < 0) return i;
      pq.pop();
    }
    return heights.size() - 1;
  }
};

class Solution_OLD {
  // Priority queue
 public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    const int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < n; ++i) {
      const int diff = heights[i] - heights[i - 1];
      if (diff <= 0) continue;
      pq.push(diff);
      if (pq.size() <= ladders) continue;
      // no enough ladder
      bricks -= pq.top();
      pq.pop();
      if (bricks < 0) return i - 1;
    }
    return n - 1;
  }
};

class Solution1 {
  // Binary search, from huahua
 public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    const int n = heights.size();
    vector<int> diffs(n);
    for (int i = 1; i < n; ++i) diffs[i - 1] = max(0, heights[i] - heights[i - 1]);
    int l = ladders, r = n;
    while (l < r) {
      const int m = (l + r) >> 1;
      vector<int> bk(diffs.begin(), diffs.begin() + m);
      nth_element(bk.begin(), bk.end() - ladders, bk.end());
      if (accumulate(bk.begin(), bk.end() - ladders, 0) > bricks)
        r = m;
      else
        l = m + 1;
    }
    return l - 1;
  }
};

class Solution_TLE1 {
  // DFS
 public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    const int last_building_idx = heights.size() - 1;
    function<int(int, int, int)> helper = [&](int building_idx, int bricks, int ladders) {
      while (building_idx != last_building_idx && heights[building_idx] >= heights[building_idx + 1]) ++building_idx;
      if (building_idx >= last_building_idx) return last_building_idx;
      int use_brick = building_idx, use_ladder = building_idx, bricks_needed =
        heights[building_idx + 1] - heights[building_idx];
      if (bricks_needed <= bricks)
        use_brick = helper(building_idx + 1, bricks - bricks_needed, ladders);
      if (ladders > 0)
        use_ladder = helper(building_idx + 1, bricks, ladders - 1);
      return max(use_brick, use_ladder);
    };
    return helper(0, bricks, ladders);
  }
};

int main() {
  Solution s;

  return 0;
}
