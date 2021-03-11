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
// DP
class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int n = 0, p = 0, res = 0;
    for (auto a : nums) {
      res = max(res, p);
      if (a > 0) {
        ++p;
        n = n != 0? n + 1 : 0;
      } else if (a < 0) {
        const int pbk = p;
        p = n != 0? n + 1 : 0;
        n = pbk + 1;
      } else {
        n = p = 0;
      }
    }
    return max(res, p);
  }
};

class Solution1 {
 public:
  int getMaxLen(vector<int>& nums) {
    const int n_size = nums.size();
    vector<int> n (n_size), p (n_size);
    if (nums[0] > 0)
      p[0] = 1;
    else if (nums[0] < 0)
      n[0] = 1;
    int res = 0;
    for (int i = 1; i < n_size; ++i) {
      res = max(res, p[i - 1]);
      if (nums[i] > 0) {
        p[i] = p[i - 1] + 1;
        n[i] = n[i - 1] != 0 ? n[i - 1] + 1 : 0;
      } else if (nums[i] < 0) {
        p[i] = n[i - 1] != 0 ? n[i - 1] + 1 : 0;
        n[i] = p[i - 1] + 1;
      } else {
        n[i] = p[i] = 0;
      }
    }
    return max(res, p.back());
  }
};



int main() {
  Solution s;
  
  return 0;
}
