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
  int totalHammingDistance(vector<int>& nums) {
    int res = 0, n = nums.size();
    for (int i=0; i<31; ++i) {
      int count = 0;
      for (int num: nums)
        if (num & (1<<i)) ++count;
      res += count * (n-count);
    }
    return res;
  }
};


class Solution_TLE {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    for (int i=0, n=nums.size()-1; i<n; ++i)
      for (int j=i+1; j<=n; ++j)
        res += __builtin_popcount(nums[i]^nums[j]);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
