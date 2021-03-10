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
// BFS with cache
class Solution {
 public:
  int minDays(int n) {
    unordered_set<int> visited;
    deque<int> dq;
    dq.push_back(n);
    int res = 0;
    while (!dq.empty()) {
      for (int i = 0, n = dq.size(); i < n; ++i) {
        int left = dq.front(); dq.pop_front();
        if (left == 0) return res;
        if (visited.count(left - 1) == 0) {
          visited.insert(left - 1);
          dq.push_back(left - 1);
        }
        if ((left & 1) == 0 && visited.count(left >> 1) == 0) {
          visited.insert(left >> 1);
          dq.push_back(left >> 1);
        }
        if (left % 3 == 0)
          if (int temp = left / 3; visited.count(left / 3) == 0) {
            visited.insert(temp);
            dq.push_back(temp);
          }
      }
      ++res;
    }
    return res;
  }
};

// I know following solutions will tle or mle, but knowing how far they can get is interesting
// DFS
class Solution_TLE3 {  // tle at 55/176 : 9609
 public:
  int minDays(int n) {
    int res = INT_MAX;
    function<void(int, int)> helper = [&] (const int a, int day) {
      if (a == 0) {
        res = min(res, day);
        return ;
      }
      ++day;
      if (day == res) return ;
      helper(a - 1, day);
      if ((a & 1) == 0)
        helper(a >> 1, day);
      if (a % 3 == 0)
        helper(a / 3, day);
    };
    helper(n, 0);
    return res;
  }
};

class Solution_TLE2 {  // tle at 45/176 : 6533
 public:
  int minDays(int n) {
    int res = INT_MAX;
    function<void(int, int)> helper = [&] (const int a, const int day) {
      if (a == 0) {
        res = min(res, day);
        return ;
      }
      if (day == res) return ;

      helper(a - 1, day + 1);
      if ((a & 1) == 0)
        helper(a >> 1, day + 1);
      if (a % 3 == 0)
        helper(a / 3, day + 1);
    };
    helper(n, 0);
    return res;
  }
};

class Solution_TLE1 {  // tle at 19/176 case : 540
 public:
  int minDays(int n) {
    vector<int> days;
    function<void(int, int)> helper = [&] (const int a, const int day) {
      if (a == 0) {
        days.emplace_back(day);
        return ;
      }
      helper(a - 1, day + 1);
      if ((a & 1) == 0)
        helper(a >> 1, day + 1);
      if (a % 3 == 0)
        helper(a / 3, day + 1);
    };
    helper(n, 0);
    return *min_element(days.begin(), days.end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
