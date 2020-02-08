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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    vector<int> pos((n<<1)+1, INT_MIN);
    int sum = 0;
    int res = 0;
    for (int i=0; i<n; ++i) {
      sum += nums[i]? 1: -1;
      if (sum == 0) {
        res = i+1;
      } else if (pos[sum+n] != INT_MIN) {
        res = max(res, i-pos[sum+n]);
      } else {
        pos[sum+n] = i;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
