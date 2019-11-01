#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  int dayOfYear(string date) {
    int year = std::stoi(date.substr(0,4), nullptr),
      mon = std::stoi(date.substr(5,2), nullptr),
      day = std::stoi(date.substr(8,2), nullptr),
      days[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
      res = day + days[mon];
    if ((mon>2) && ((year%4==0&&year%100!=0) || (year%400==0)))
      res += 1;
    return res;
  }
};

int main() {
  Solution s;
  string a = "2016-02-29";
  cout << s.dayOfYear(a) << endl;
  return 0;
}
