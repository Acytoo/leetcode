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
3#include <functional>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> far(ranges.size());
    for (int i=0; i<=n; ++i) {
      int start = max(0, i-ranges[i]);
      far[start] = i+ranges[i];
    }

    int res = 0, cur = 0, i = 0;
    while (cur < n) {
      ++res;
      int pre = cur;
      for (; i<=pre; ++i)
        cur = max(cur, far[i]);
      if (cur == pre)
        return -1;
    }
    return res;
  }
};

class Solution1 {
 public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> far(ranges.size());
    for (int i=0; i<=n; ++i) {
      int start = max(0, i-ranges[i]);
      far[start] = i+ranges[i];
    }

    int res = 0, cur = 0, last = 0;
    for (int i=0; i<=n; ++i) {
      if (cur < i)
        return -1;
      if (last < cur) {
        ++res;
        last = i;
      }
      cur = max(cur, far[i]);
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
