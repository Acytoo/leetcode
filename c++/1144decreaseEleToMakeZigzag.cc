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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int movesToMakeZigzag(vector<int>& nums) {
    const int n = nums.size()-1;
    vector<int> moves(2);
    for (int i=0; i<=n; ++i) {
      int l = i == 0? INT_MAX: nums[i-1];
      int r = i == n? INT_MAX: nums[i+1];
      moves[i & 1] += max(0, nums[i] - min(l, r) + 1);
    }
    return min(moves[0], moves[1]);
  }
};

int main() {
  Solution s;
  
  return 0;
}
