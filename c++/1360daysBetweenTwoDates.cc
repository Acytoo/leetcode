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
  int daysBetweenDates(string date1, string date2) {
    return abs(to_days(date1) - to_days(date2));
  }
 private:
  vector<int> mo_ = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int to_days(const string& s) {
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    for (int i=1971; i<year; ++i)
      day += 365 + is_leap(i);
    for (int i=1; i<month; ++i)
      day += mo_[i];
    day += month>2? is_leap(year): 0;
    return day;
  }
  const inline bool is_leap(int year) {
    return year % 4 == 0 && (year % 400 == 0 || year % 100 != 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
