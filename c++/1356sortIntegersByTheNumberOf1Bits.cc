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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= arr.length <= 500
// 0 <= arr[i] <= 10^4
class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&] (const int a, const int b) {
      const int na = __builtin_popcount(a);
      const int nb = __builtin_popcount(b);
      if (na != nb) return na < nb;
      return a < b;
    });
    return arr;
  }
};

class Solution_OLD {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&] (const int a, const int b) {
      int aa = 0, bb = 0;
      for (int i=0; i<15; ++i) {
        int tmp = 1 << i;
        if (a & tmp)
          ++aa;
        if (b & tmp)
          ++bb;
      }
      return aa != bb ? aa < bb : a < b ;
    });
    return arr;
  }
};

int main() {
  Solution s;
  
  return 0;
}
