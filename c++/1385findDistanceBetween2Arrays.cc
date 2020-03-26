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
// Brute force
class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int res = 0, n = arr2.size();
    for (const int a: arr1) {
      int i = 0;
      while (i<n) {
        if (abs(a-arr2[i]) <= d)
          break;
        ++i;
      }
      if (i == n)
        ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
