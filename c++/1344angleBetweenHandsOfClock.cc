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
  double angleClock(int hour, int minutes) {
    hour = hour == 12? 0: hour;
    double ha = (hour / 12.0) + (minutes / 720.0);
    double ma = minutes / 60.0;
    double diff = abs(ha-ma);
    diff = diff <= 0.5? diff: diff - 0.5;
    return diff * 360.0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
