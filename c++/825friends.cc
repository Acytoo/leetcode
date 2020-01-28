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
  int numFriendRequests(vector<int>& ages) {
    int res = 0;
    int reqs[121]{0};
    bool checked[121]{false};

    for (int i=0, stop=ages.size()-1; i<=stop; ++i) {
      if (checked[ages[i]]) {
        res += reqs[ages[i]];
        continue;
      }

      int req = 0;
      for (int j=0; j<i; ++j) {
        if (ages[j]<=ages[i] &&  ages[j] > (ages[i]>>1)+7)
          ++req;
      }
      for (int j=i+1; j<=stop; ++j) {
        if (ages[j]<=ages[i] &&  ages[j] > (ages[i]>>1)+7)
          ++req;
      }
      res += req;

      checked[ages[i]] = true;
      reqs[ages[i]] = req;
    }
    return res;
  }
};

class Solution1 {
 public:
  int numFriendRequests(vector<int>& ages) {
    int res = 0, lastReq = 0, lastAge = 0;
    sort(ages.begin(), ages.end(), greater <>());

    for (int i=0, stop=ages.size()-1; i<=stop; ++i) {
      if (ages[i] == lastAge) {
        res += lastReq;
        continue;
      }

      int req = 0;
      for (int j=i+1; j<=stop; ++j) {
        if (ages[j] > (ages[i]>>1)+7)
          ++req;
      }
      res += req;
      lastAge = ages[i];
      lastReq = req;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
