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
  string reformatDate(string date) {
    string day, mon, res;
    stringstream ss (date);
    ss >> day >> mon >> res;
    switch (mon.back()) {
      case 'n':
        if (mon[1] == 'a')
          res += "-01-";
        else
          res += "-06-";
        break;
      case 'b': res += "-02-"; break;
      case 'r':
        if (mon.front() == 'M')
          res += "-03-";
        else
          res += "-04-";
        break;
      case 'y': res += "-05-"; break;
      case 'l': res += "-07-"; break;
      case 'g': res += "-08-"; break;
      case 'p': res += "-09-"; break;
      case 't': res += "-10-"; break;
      case 'v': res += "-11-"; break;
      case 'c': res += "-12-"; break;
    }
    int d = 0;
    sscanf(day.c_str(), "%d", &d);
    if (d < 10)
      res += '0' + to_string(d);
    else
      res += to_string(d);
    return res;
  }
};

int main() {
  Solution s;
  string a = "20th Oct 2052";
  cout << s.reformatDate(a) << endl;
  return 0;
}
