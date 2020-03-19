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
// The given dates are valid dates between the years 1971 and 2100.
class Solution {
 public:
  string dayOfTheWeek(int day, int month, int year) {
    vector<string> names = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                            "Friday", "Saturday"};
    vector<int> mo = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // int day = 0;
    for (int i=1971; i<year; ++i)
      day += 365 + is_leap(i);
    for (int i=1; i<month; ++i)
      day += mo[i];
    if (month>2 && is_leap(year))
      ++day;
    //day += day;
    return names[(day+4)%7]; // 1971 1 1 is Friday
  }
 private:
  const inline bool is_leap(int year) {
    return year % 4 == 0 && (year % 400 == 0 || year % 100 != 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
