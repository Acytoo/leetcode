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
  int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    if (n < 3)
      return 0;
    sort(nums.rbegin(), nums.rend());  // rbegin, rend ---> sort(greater<>())
    // sort(nums.begin(), nums.end(), greater<int>());
    int res = 0;
    n -= 2;
    for (int i=0; i<n; ++i) {
      int j = i + 1, k = n + 1;
      while (j < k) {
        if (nums[i] < nums[j] + nums[k]) {
          res += (k-j);
          ++j;
        } else {
          --k;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
