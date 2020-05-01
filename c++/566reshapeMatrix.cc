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
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    const int m = nums.size(), n = nums[0].size();
    if (m * n != r * c) return nums;

    vector<vector<int>> res (r, vector<int> (c));
    int mm = 0, nn = 0;
    for (int i=0; i<r; ++i)
      for (int j=0; j<c; ++j) {
        if (nn == n) {nn = 0; ++mm;}
        res[i][j] = nums[mm][nn];
        ++nn;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
