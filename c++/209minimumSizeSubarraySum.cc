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
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    bool has_res = false;
    int l = 0, sum = 0, res = INT_MAX;
    for (int i=0, stop=nums.size(); i<stop; ++i) {
      sum += nums[i];
      while (sum >= s) {
        has_res = true;
        res = min(res, i-l+1);
        sum -= nums[l++];
      }
    }
    return has_res? res: 0;
  }
};


class Solution1 {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return false;
    int l = 0, r = 0, sum = 0, res = INT_MAX, last_r = -1;
    bool has_res = false;
    while (r < n && l <= r) {
      if (r != last_r)
        sum += nums[r];
      if (sum >= s) {
        has_res = true;
        res = min(res, r-l+1);
        sum -= nums[l];
        ++l;
        last_r = r;
      } else {
        last_r = r++;
      }
    }
    return has_res? res: 0;
  }
};


int main() {
  Solution s;
  
  return 0;
}
