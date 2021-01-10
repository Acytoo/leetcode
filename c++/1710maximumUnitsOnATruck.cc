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
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [&](const vector<int> &a, const vector <int> &b) { return a[1] > b[1]; });
    int res = 0;
    for (const auto &b: boxTypes) {
      if (truckSize == 0) return res;
      const int t = min(truckSize, b[0]);
      res += t * b[1];
      truckSize -= t;
    }
    return res;
  }
};

class Solution1 {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    const int n = boxTypes.size();
    sort(boxTypes.begin(), boxTypes.end(),
         [&](const vector<int> &a, const vector <int> &b) { return a[1] > b[1]; });
    int i = 0, res = 0;
    while (i < n && truckSize > 0) {
      if (truckSize > boxTypes[i][0]) {
        truckSize -= boxTypes[i][0];
        res += boxTypes[i][0] * boxTypes[i][1];
      } else {
        res += truckSize * boxTypes[i][1];
        truckSize = 0;
      }
      ++i;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
