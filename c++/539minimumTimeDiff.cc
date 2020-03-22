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
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int res = INT_MAX;
    for (int i=0, stop=timePoints.size()-1; i<stop; ++i) {
      res = min(res, diff(timePoints[i], timePoints[i+1]));
      if (res == 0)
        return 0;
    }
    res = min(res, diff(timePoints.back(), timePoints[0], 24));
    return res;
  }
 private:
  inline int diff(const string& a, const string& b, int base = 0) {
    return (stoi(b.substr(0, 2))-stoi(a.substr(0, 2))+base) * 60 + (stoi(b.substr(3, 2)) - stoi(a.substr(3,2)));
  }
};

int main() {
  Solution s;
  vector<string> a = {"23:59","00:00"};
  cout << s.findMinDifference(a) << endl;
  return 0;
}
