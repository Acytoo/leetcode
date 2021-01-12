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
  // each week 7
 public:
  int totalMoney(int n) {
    constexpr int first_week = 1 + 2 + 3 + 4 + 5 + 6 + 7;
    int res = 0, cur_monday = 1, cur_week = first_week, cur_date = 0;
    while (cur_date < n) {
      if (cur_date + 7 < n) {
        res += cur_week;
        cur_week += 7;
        ++cur_monday;
        cur_date += 7;
      } else {
        while (cur_date < n) {
          res += cur_monday++;
          ++cur_date;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
