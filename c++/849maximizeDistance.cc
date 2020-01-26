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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int res = 0;
    int curDis = 0, lastSeat = 0, n = seats.size()-1;
    while (res <= n && seats[res] == 0) ++res;
    lastSeat = 1;
    for (int i=res+1, stop=seats.size(); i<stop; ++i) {
      if (seats[i] == 1) {  // not empty
        if (lastSeat == 0) {  // last seat is empty, then we calculate current distance
          int tmp = (curDis >> 1) + (curDis & 1);
          res = max(res, tmp);
          curDis = 0;
        }
        lastSeat = 1;
      } else {  // empty seat
        if (lastSeat == 1) {  // first empty seat
          curDis = 1;
        } else {  // not first empty
          ++curDis;
        }
        lastSeat = 0;
      }
    }
    res = max(res, curDis);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
