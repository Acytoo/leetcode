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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int left = 0;
    for (const auto &a: shift)
      if (a[0])
        left -= a[1];
      else
        left += a[1];
    const int n = s.size();
    left %= n;
    if (left == 0) return s;

    string res = s + s;
    if (left < 0) left += n;
    return res.substr(left, n);
  }
};

int main() {
  Solution s;
  
  return 0;
}
