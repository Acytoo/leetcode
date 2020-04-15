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
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res (n);
    res[0] = 1;
    for (int i=1; i<n; ++i)
      res[i] = res[i-1] * nums[i-1];
    int right = 1;
    for (int i=n-2; i>=0; --i) {
      right *= nums[i+1];
      res[i] *= right;
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
