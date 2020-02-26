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
  int findTargetSumWays(vector<int>& nums, int S) {
    const int n = nums.size();
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum < S) return 0;

    const int offset = sum;
    vector<vector<int>> ways(n+1, vector<int>(sum+offset+1, 0));
    ways[0][offset] = 1;

    for (int i=0; i<n; ++i) {
      for (int j=nums[i]; j<(sum*2)+1-nums[i]; ++j)

        if (ways[i][j]) {
          ways[i+1][j+nums[i]] += ways[i][j];
          ways[i+1][j-nums[i]] += ways[i][j];
        }
    }
    return ways.back()[S+offset];
  }
};

int main() {
  Solution s;
  
  return 0;
}
