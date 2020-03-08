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


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if ((sum & 1) == 1)  // odd
      return false;
    int target = sum >> 1;
    vector<bool> dp (sum+1, false);
    dp[0] = true;
    for (const int num: nums) {
      for (int i=sum; i>=0; --i)  // 从大到小
        if (dp[i])
          dp[i+num] = true;
      if (dp[target])
        return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
