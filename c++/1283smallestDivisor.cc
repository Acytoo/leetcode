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
  // Binary search
  int smallestDivisor(vector<int>& nums, int threshold) {
    auto divisorSum = [&nums](int d) {
                        int sum = 0;
                        for (const int num: nums)
                          // sum += static_cast<int>(ceil(static_cast<double>(num) / d));
                          sum += (num - 1 + d) / d;
                        return sum;
                      };
    int l = 1, r = 1e6;
    while (l < r) {
      int m = (l+r) >> 1;
      if (divisorSum(m) <= threshold)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

int main() {
  Solution s;
  
  return 0;
}
