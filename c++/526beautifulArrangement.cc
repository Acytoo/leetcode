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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countArrangement(int N) {
    vector<int> nums (N);
    for (int i=0; i<N; ++i) nums[i] = i + 1;
    function<int(int)> helper =
        [&] (int n) {
          if (n <= 0) return 1;
          int res = 0;
          for (int i=0; i<n; ++i)
            if (n % nums[i] == 0 || nums[i] % n == 0) {
              swap(nums[i], nums[n-1]);
              res += helper(n-1);
              swap(nums[i], nums[n-1]);
            }
          return res;
        };
    return helper(N);
  }
};

class Solution_table {
  // 1 <= N <= 15
 public:
  int countArrangement(int N) {
    switch (N) {
      case 1: return 1;
      case 2: return 2;
      case 3: return 3;
      case 4: return 8;
      case 5: return 10;
      case 6: return 36;
      case 7: return 41;
      case 8: return 132;
      case 9: return 250;
      case 10: return 700;
      case 11: return 750;
      case 12: return 4010;
      case 13: return 4237;
      case 14: return 10680;
      case 15: return 24679;
      default: return 1;
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
