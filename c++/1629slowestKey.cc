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
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    char res = keysPressed[0];
    int res_time_pressed = releaseTimes[0];
    for (int i = 1, n = releaseTimes.size(); i < n; ++i) {
      const int cur_pressed_time = releaseTimes[i] - releaseTimes[i - 1];
      if (cur_pressed_time > res_time_pressed) {
        res_time_pressed = cur_pressed_time;
        res = keysPressed[i];
      } else if (cur_pressed_time == res_time_pressed) {
        res = max(res, keysPressed[i]);
      }
    }
    return res;
  }
};

// O(N)
class Solution1 {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    const int n = releaseTimes.size();
    vector<int> time_pressed = {releaseTimes[0]};
    time_pressed.reserve(n);
    for (int i = 1; i < n; ++i) time_pressed[i] = releaseTimes[i] - releaseTimes[i - 1];
    char res = keysPressed[0];
    int longest = time_pressed[0];
    for (int i = 1; i < n; ++i)
      if (longest < time_pressed[i]) {
        longest = time_pressed[i];
        res = keysPressed[i];
      } else if (longest == time_pressed[i] && res < keysPressed[i]) {
        res = keysPressed[i];
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
