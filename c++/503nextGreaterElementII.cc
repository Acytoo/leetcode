#include <iostream>
#include <sstream>
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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
  // Brute force
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
      int j = i + 1, k = 0;
      for (; k < n; ++k) {
        int jj = k + j;
        if (jj >= n) jj -= n;
        if (nums[jj] > nums[i]) {
          res.emplace_back(nums[jj]);
          break;
        }
      }
      if (k == n) res.emplace_back(-1);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
