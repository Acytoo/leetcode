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
  string maximumTime(string time) {
    if (time[0] == '?') {
      if (time[1] == '?') {
        time[0] = '2';
        time[1] = '3';
      } else if (time[1] <= '3') {
        time[0] = '2';
      } else {
        time[0] = '1';
      }
    } else if (time[1] == '?') {
      if (time[0] <= '1')  // 0 / 1
        time[1] = '9';
      else
        time[1] = '3';
    }

    if (time[3] == '?') {
      time[3] = '5';
    }
    if (time[4] == '?') {
      time[4] = '9';
    }
    return time;
  }
};

int main() {
  Solution s;
  
  return 0;
}
